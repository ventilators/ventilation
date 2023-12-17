#include <gtest/gtest.h>
#include <rapidcheck/gtest.h>
#include <ventilation/ventilation.hpp>

#include "test-arbitrary.hpp"

using P64 = ventilation::PEEP<double>;

// Tests single precision peak pressure implementation
namespace f32 {
    using PEEP = ventilation::PEEP<float>;
    RC_GTEST_PROP(Add, Associative, (const PEEP& xs, const PEEP& ys, const PEEP& zs)) {
        RC_ASSERT(((xs + ys) + zs) == (xs + ys + zs));
    }

    RC_GTEST_PROP(Add, Commutative, (const PEEP& xs, const PEEP& ys)) {
        RC_ASSERT((xs + ys) == (ys + xs));
    }

    RC_GTEST_PROP(Add, Neutral, (const PEEP& xs)) {
        PEEP ys(0.0f);
        RC_ASSERT((xs + ys) == xs);
    }

    RC_GTEST_PROP(Add, Successor, (const PEEP& xs)) {
        PEEP ys(1.0f);
        RC_ASSERT((xs + ys) != xs);
    }

    RC_GTEST_PROP(Mul, Associative, (const PEEP& xs, const PEEP& ys, const PEEP& zs)) {
        RC_ASSERT(((xs * ys) * zs) == (xs * ys * zs));
    }

    RC_GTEST_PROP(Mul, Commutative, (const PEEP& xs, const PEEP& ys)) {
        RC_ASSERT((xs * ys) == (ys * xs));
    }

    RC_GTEST_PROP(Mul, Neutral, (const PEEP& xs)) {
        PEEP ys(1.0f);
        RC_ASSERT((xs * ys) == xs);
    }

    RC_GTEST_PROP(Mul, Zero, (const PEEP& xs)) {
        PEEP ys(0.0f);
        RC_ASSERT((xs * ys) == ys);
    }

    RC_GTEST_PROP(MulScalar, Commutative, (const PEEP& xs)) {
        float ys = *rc::gen::inRange(-100, 100);
        RC_ASSERT((xs * ys) == (ys * xs));
    }

    RC_GTEST_PROP(MulScalar, Neutral, (const PEEP& xs)) {
        float ys = 1.0f;
        RC_ASSERT((xs * ys) == PEEP(xs));
    }

    RC_GTEST_PROP(MulScalar, Zero, (const PEEP& xs)) {
        float ys = 0.0f;
        RC_ASSERT((xs * ys) == PEEP(ys));
    }

    RC_GTEST_PROP(Comparison, Greater, (const PEEP& xs)) {
        PEEP ys(1.0f);
        RC_ASSERT((xs + ys) > xs);
        RC_ASSERT((xs + ys) >= xs);
    }

    RC_GTEST_PROP(Comparison, Lesser, (const PEEP& xs)) {
        PEEP ys(1.0f);
        RC_ASSERT(xs <  (xs + ys));
        RC_ASSERT(xs <= (xs + ys));
    }
} // namespace f32
// Tests double precision peak pressure implementation
namespace f64 {
    using PEEP = ventilation::PEEP<double>;
    RC_GTEST_PROP(Add, Associative, (const PEEP& xs, const PEEP& ys, const PEEP& zs)) {
        RC_ASSERT(((xs + ys) + zs) == (xs + ys + zs));
    }

    RC_GTEST_PROP(Add, Commutative, (const PEEP& xs, const PEEP& ys)) {
        RC_ASSERT((xs + ys) == (ys + xs));
    }

    RC_GTEST_PROP(Add, Neutral, (const PEEP& xs)) {
        PEEP ys(0.0);
        RC_ASSERT((xs + ys) == xs);
    }

    RC_GTEST_PROP(Add, Successor, (const PEEP& xs)) {
        PEEP ys(1.0);
        RC_ASSERT((xs + ys) != xs);
    }

    RC_GTEST_PROP(Mul, Associative, (const PEEP& xs, const PEEP& ys, const PEEP& zs)) {
        RC_ASSERT(((xs * ys) * zs) == (xs * ys * zs));
    }

    RC_GTEST_PROP(Mul, Commutative, (const PEEP& xs, const PEEP& ys)) {
        RC_ASSERT((xs * ys) == (ys * xs));
    }

    RC_GTEST_PROP(Mul, Neutral, (const PEEP& xs)) {
        PEEP ys(1.0);
        RC_ASSERT((xs * ys) == xs);
    }

    RC_GTEST_PROP(Mul, Zero, (const PEEP& xs)) {
        PEEP ys(0.0);
        RC_ASSERT((xs * ys) == ys);
    }

    RC_GTEST_PROP(MulScalar, Commutative, (const PEEP& xs)) {
        double ys = *rc::gen::inRange(-100, 100);
        RC_ASSERT((xs * ys) == (ys * xs));
    }

    RC_GTEST_PROP(MulScalar, Neutral, (const PEEP& xs)) {
        double ys = 1.0;
        RC_ASSERT((xs * ys) == PEEP(xs));
    }

    RC_GTEST_PROP(MulScalar, Zero, (const PEEP& xs)) {
        double ys = 0.0;
        RC_ASSERT((xs * ys) == PEEP(ys));
    }

    RC_GTEST_PROP(Comparison, Greater, (const PEEP& xs)) {
        PEEP ys(1.0);
        RC_ASSERT((xs + ys) > xs);
        RC_ASSERT((xs + ys) >= xs);
    }

    RC_GTEST_PROP(Comparison, Lesser, (const PEEP& xs)) {
        PEEP ys(1.0);
        RC_ASSERT(xs <  (xs + ys));
        RC_ASSERT(xs <= (xs + ys));
    }
} // namespace f64
// Tests long double precision peak pressure implementation
namespace f128 {
    using PEEP = ventilation::PEEP<long double>;
    RC_GTEST_PROP(Add, Associative, (const PEEP& xs, const PEEP& ys, const PEEP& zs)) {
        RC_ASSERT(((xs + ys) + zs) == (xs + ys + zs));
    }

    RC_GTEST_PROP(Add, Commutative, (const PEEP& xs, const PEEP& ys)) {
        RC_ASSERT((xs + ys) == (ys + xs));
    }

    RC_GTEST_PROP(Add, Neutral, (const PEEP& xs)) {
        PEEP ys(0.0);
        RC_ASSERT((xs + ys) == xs);
    }

    RC_GTEST_PROP(Add, Successor, (const PEEP& xs)) {
        PEEP ys(1.0);
        RC_ASSERT((xs + ys) != xs);
    }

    RC_GTEST_PROP(Mul, Associative, (const PEEP& xs, const PEEP& ys, const PEEP& zs)) {
        RC_ASSERT(((xs * ys) * zs) == (xs * ys * zs));
    }

    RC_GTEST_PROP(Mul, Commutative, (const PEEP& xs, const PEEP& ys)) {
        RC_ASSERT((xs * ys) == (ys * xs));
    }

    RC_GTEST_PROP(Mul, Neutral, (const PEEP& xs)) {
        PEEP ys(1.0);
        RC_ASSERT((xs * ys) == xs);
    }

    RC_GTEST_PROP(Mul, Zero, (const PEEP& xs)) {
        PEEP ys(0.0);
        RC_ASSERT((xs * ys) == ys);
    }

    RC_GTEST_PROP(MulScalar, Commutative, (const PEEP& xs)) {
        long double ys = *rc::gen::inRange(-100, 100);
        RC_ASSERT((xs * ys) == (ys * xs));
    }

    RC_GTEST_PROP(MulScalar, Neutral, (const PEEP& xs)) {
        long double ys = 1.0;
        RC_ASSERT((xs * ys) == PEEP(xs));
    }

    RC_GTEST_PROP(MulScalar, Zero, (const PEEP& xs)) {
        long double ys = 0.0;
        RC_ASSERT((xs * ys) == PEEP(ys));
    }

    RC_GTEST_PROP(Comparison, Greater, (const PEEP& xs)) {
        PEEP ys(1.0);
        RC_ASSERT((xs + ys) > xs);
        RC_ASSERT((xs + ys) >= xs);
    }

    RC_GTEST_PROP(Comparison, Lesser, (const PEEP& xs)) {
        PEEP ys(1.0);
        RC_ASSERT(xs <  (xs + ys));
        RC_ASSERT(xs <= (xs + ys));
    }
} // namespace f128

int
main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
