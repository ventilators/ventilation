#include <gtest/gtest.h>
#include <rapidcheck/gtest.h>
#include <ventilation/ventilation.hpp>

#include "test-arbitrary.hpp"

// Tests single precision pressure implementation
namespace f32 {
    using Pressure = ventilation::Pressure<float>;
    RC_GTEST_PROP(Add, Associative, (const Pressure& xs, const Pressure& ys, const Pressure& zs)) {
        RC_ASSERT(((xs + ys) + zs) == (xs + ys + zs));
    }

    RC_GTEST_PROP(Add, Commutative, (const Pressure& xs, const Pressure& ys)) {
        RC_ASSERT((xs + ys) == (ys + xs));
    }

    RC_GTEST_PROP(Add, Neutral, (const Pressure& xs)) {
        Pressure ys(0.0f);
        RC_ASSERT((xs + ys) == xs);
    }

    RC_GTEST_PROP(Add, Successor, (const Pressure& xs)) {
        Pressure ys(1.0f);
        RC_ASSERT((xs + ys) != xs);
    }

    RC_GTEST_PROP(Mul, Associative, (const Pressure& xs, const Pressure& ys, const Pressure& zs)) {
        RC_ASSERT(((xs * ys) * zs) == (xs * ys * zs));
    }

    RC_GTEST_PROP(Mul, Commutative, (const Pressure& xs, const Pressure& ys)) {
        RC_ASSERT((xs * ys) == (ys * xs));
    }

    RC_GTEST_PROP(Mul, Neutral, (const Pressure& xs)) {
        Pressure ys(1.0f);
        RC_ASSERT((xs * ys) == xs);
    }

    RC_GTEST_PROP(Mul, Zero, (const Pressure& xs)) {
        Pressure ys(0.0f);
        RC_ASSERT((xs * ys) == ys);
    }

    RC_GTEST_PROP(MulScalar, Commutative, (const Pressure& xs)) {
        float ys = *rc::gen::inRange(-100, 100);
        RC_ASSERT((xs * ys) == (ys * xs));
    }

    RC_GTEST_PROP(MulScalar, Neutral, (const Pressure& xs)) {
        float ys = 1.0f;
        RC_ASSERT((xs * ys) == Pressure(xs));
    }

    RC_GTEST_PROP(MulScalar, Zero, (const Pressure& xs)) {
        float ys = 0.0f;
        RC_ASSERT((xs * ys) == Pressure(ys));
    }

    RC_GTEST_PROP(Comparison, Greater, (const Pressure& xs)) {
        Pressure ys(1.0f);
        RC_ASSERT((xs + ys) > xs);
        RC_ASSERT((xs + ys) >= xs);
    }

    RC_GTEST_PROP(Comparison, Lesser, (const Pressure& xs)) {
        Pressure ys(1.0f);
        RC_ASSERT(xs <  (xs + ys));
        RC_ASSERT(xs <= (xs + ys));
    }
} // namespace f32
// Tests double precision pressure implementation
namespace f64 {
    using Pressure = ventilation::Pressure<double>;
    RC_GTEST_PROP(Add, Associative, (const Pressure& xs, const Pressure& ys, const Pressure& zs)) {
        RC_ASSERT(((xs + ys) + zs) == (xs + ys + zs));
    }

    RC_GTEST_PROP(Add, Commutative, (const Pressure& xs, const Pressure& ys)) {
        RC_ASSERT((xs + ys) == (ys + xs));
    }

    RC_GTEST_PROP(Add, Neutral, (const Pressure& xs)) {
        Pressure ys(0.0);
        RC_ASSERT((xs + ys) == xs);
    }

    RC_GTEST_PROP(Add, Successor, (const Pressure& xs)) {
        Pressure ys(1.0);
        RC_ASSERT((xs + ys) != xs);
    }

    RC_GTEST_PROP(Mul, Associative, (const Pressure& xs, const Pressure& ys, const Pressure& zs)) {
        RC_ASSERT(((xs * ys) * zs) == (xs * ys * zs));
    }

    RC_GTEST_PROP(Mul, Commutative, (const Pressure& xs, const Pressure& ys)) {
        RC_ASSERT((xs * ys) == (ys * xs));
    }

    RC_GTEST_PROP(Mul, Neutral, (const Pressure& xs)) {
        Pressure ys(1.0f);
        RC_ASSERT((xs * ys) == xs);
    }

    RC_GTEST_PROP(Mul, Zero, (const Pressure& xs)) {
        Pressure ys(0.0f);
        RC_ASSERT((xs * ys) == ys);
    }

    RC_GTEST_PROP(MulScalar, Commutative, (const Pressure& xs)) {
        double ys = *rc::gen::inRange(-100, 100);
        RC_ASSERT((xs * ys) == (ys * xs));
    }

    RC_GTEST_PROP(MulScalar, Neutral, (const Pressure& xs)) {
        double ys = 1.0;
        RC_ASSERT((xs * ys) == Pressure(xs));
    }

    RC_GTEST_PROP(MulScalar, Zero, (const Pressure& xs)) {
        double ys = 0.0;
        RC_ASSERT((xs * ys) == Pressure(ys));
    }

    RC_GTEST_PROP(Comparison, Greater, (const Pressure& xs)) {
        Pressure ys(1.0);
        RC_ASSERT((xs + ys) > xs);
        RC_ASSERT((xs + ys) >= xs);
    }

    RC_GTEST_PROP(Comparison, Lesser, (const Pressure& xs)) {
        Pressure ys(1.0);
        RC_ASSERT(xs <  (xs + ys));
        RC_ASSERT(xs <= (xs + ys));
    }
} // namespace f64
// Tests long double precision pressure implementation
namespace f128 {
    using Pressure = ventilation::Pressure<long double>;
    RC_GTEST_PROP(Add, Associative, (const Pressure& xs, const Pressure& ys, const Pressure& zs)) {
        RC_ASSERT(((xs + ys) + zs) == (xs + ys + zs));
    }

    RC_GTEST_PROP(Add, Commutative, (const Pressure& xs, const Pressure& ys)) {
        RC_ASSERT((xs + ys) == (ys + xs));
    }

    RC_GTEST_PROP(Add, Neutral, (const Pressure& xs)) {
        Pressure ys(0.0);
        RC_ASSERT((xs + ys) == xs);
    }

    RC_GTEST_PROP(Add, Successor, (const Pressure& xs)) {
        Pressure ys(1.0);
        RC_ASSERT((xs + ys) != xs);
    }

    RC_GTEST_PROP(Mul, Associative, (const Pressure& xs, const Pressure& ys, const Pressure& zs)) {
        RC_ASSERT(((xs * ys) * zs) == (xs * ys * zs));
    }

    RC_GTEST_PROP(Mul, Commutative, (const Pressure& xs, const Pressure& ys)) {
        RC_ASSERT((xs * ys) == (ys * xs));
    }

    RC_GTEST_PROP(Mul, Neutral, (const Pressure& xs)) {
        Pressure ys(1.0);
        RC_ASSERT((xs * ys) == xs);
    }

    RC_GTEST_PROP(Mul, Zero, (const Pressure& xs)) {
        Pressure ys(0.0);
        RC_ASSERT((xs * ys) == ys);
    }

    RC_GTEST_PROP(MulScalar, Commutative, (const Pressure& xs)) {
        long double ys = *rc::gen::inRange(-100, 100);
        RC_ASSERT((xs * ys) == (ys * xs));
    }

    RC_GTEST_PROP(MulScalar, Neutral, (const Pressure& xs)) {
        long double ys = 1.0;
        RC_ASSERT((xs * ys) == Pressure(xs));
    }

    RC_GTEST_PROP(MulScalar, Zero, (const Pressure& xs)) {
        long double ys = 0.0;
        RC_ASSERT((xs * ys) == Pressure(ys));
    }

    RC_GTEST_PROP(Comparison, Greater, (const Pressure& xs)) {
        Pressure ys(1.0);
        RC_ASSERT((xs + ys) > xs);
        RC_ASSERT((xs + ys) >= xs);
    }

    RC_GTEST_PROP(Comparison, Lesser, (const Pressure& xs)) {
        Pressure ys(1.0);
        RC_ASSERT(xs <  (xs + ys));
        RC_ASSERT(xs <= (xs + ys));
    }
} // namespace f128

int
main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
