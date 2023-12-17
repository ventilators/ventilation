#include <gtest/gtest.h>
#include <rapidcheck/gtest.h>
#include <ventilation/ventilation.hpp>

#include "test-arbitrary.hpp"

// Tests single precision compliance implementation
namespace f32 {
    using Compliance = ventilation::Compliance<float>;
    RC_GTEST_PROP(Add, Associative, (const Compliance& xs, const Compliance& ys, const Compliance& zs)) {
        RC_ASSERT(((xs + ys) + zs) == (xs + ys + zs));
    }

    RC_GTEST_PROP(Add, Commutative, (const Compliance& xs, const Compliance& ys)) {
        RC_ASSERT((xs + ys) == (ys + xs));
    }

    RC_GTEST_PROP(Add, Neutral, (const Compliance& xs)) {
        Compliance ys(0.0f);
        RC_ASSERT((xs + ys) == xs);
    }

    RC_GTEST_PROP(Add, Successor, (const Compliance& xs)) {
        Compliance ys(1.0f);
        RC_ASSERT((xs + ys) != xs);
    }

    RC_GTEST_PROP(Mul, Associative, (const Compliance& xs, const Compliance& ys, const Compliance& zs)) {
        RC_ASSERT(((xs * ys) * zs) == (xs * ys * zs));
    }

    RC_GTEST_PROP(Mul, Commutative, (const Compliance& xs, const Compliance& ys)) {
        RC_ASSERT((xs * ys) == (ys * xs));
    }

    RC_GTEST_PROP(Mul, Neutral, (const Compliance& xs)) {
        Compliance ys(1.0f);
        RC_ASSERT((xs * ys) == xs);
    }

    RC_GTEST_PROP(Mul, Zero, (const Compliance& xs)) {
        Compliance ys(0.0f);
        RC_ASSERT((xs * ys) == ys);
    }

    RC_GTEST_PROP(Comparison, Greater, (const Compliance& xs)) {
        Compliance ys(1.0f);
        RC_ASSERT((xs + ys) > xs);
        RC_ASSERT((xs + ys) >= xs);
    }

    RC_GTEST_PROP(Comparison, Lesser, (const Compliance& xs)) {
        Compliance ys(1.0f);
        RC_ASSERT(xs <  (xs + ys));
        RC_ASSERT(xs <= (xs + ys));
    }
} // namespace f32
// Tests double precision compliance implementation
namespace f64 {
    using Compliance = ventilation::Compliance<double>;
    RC_GTEST_PROP(Add, Associative, (const Compliance& xs, const Compliance& ys, const Compliance& zs)) {
        RC_ASSERT(((xs + ys) + zs) == (xs + ys + zs));
    }

    RC_GTEST_PROP(Add, Commutative, (const Compliance& xs, const Compliance& ys)) {
        RC_ASSERT((xs + ys) == (ys + xs));
    }

    RC_GTEST_PROP(Add, Neutral, (const Compliance& xs)) {
        Compliance ys(0.0);
        RC_ASSERT((xs + ys) == xs);
    }

    RC_GTEST_PROP(Add, Successor, (const Compliance& xs)) {
        Compliance ys(1.0);
        RC_ASSERT((xs + ys) != xs);
    }

    RC_GTEST_PROP(Mul, Associative, (const Compliance& xs, const Compliance& ys, const Compliance& zs)) {
        RC_ASSERT(((xs * ys) * zs) == (xs * ys * zs));
    }

    RC_GTEST_PROP(Mul, Commutative, (const Compliance& xs, const Compliance& ys)) {
        RC_ASSERT((xs * ys) == (ys * xs));
    }

    RC_GTEST_PROP(Mul, Neutral, (const Compliance& xs)) {
        Compliance ys(1.0);
        RC_ASSERT((xs * ys) == xs);
    }

    RC_GTEST_PROP(Mul, Zero, (const Compliance& xs)) {
        Compliance ys(0.0);
        RC_ASSERT((xs * ys) == ys);
    }

    RC_GTEST_PROP(Comparison, Greater, (const Compliance& xs)) {
        Compliance ys(1.0);
        RC_ASSERT((xs + ys) > xs);
        RC_ASSERT((xs + ys) >= xs);
    }

    RC_GTEST_PROP(Comparison, Lesser, (const Compliance& xs)) {
        Compliance ys(1.0);
        RC_ASSERT(xs <  (xs + ys));
        RC_ASSERT(xs <= (xs + ys));
    }
} // namespace f64
// Tests long double precision compliance implementation
namespace f128 {
    using Compliance = ventilation::Compliance<long double>;
    RC_GTEST_PROP(Add, Associative, (const Compliance& xs, const Compliance& ys, const Compliance& zs)) {
        RC_ASSERT(((xs + ys) + zs) == (xs + ys + zs));
    }

    RC_GTEST_PROP(Add, Commutative, (const Compliance& xs, const Compliance& ys)) {
        RC_ASSERT((xs + ys) == (ys + xs));
    }

    RC_GTEST_PROP(Add, Neutral, (const Compliance& xs)) {
        Compliance ys(0.0);
        RC_ASSERT((xs + ys) == xs);
    }

    RC_GTEST_PROP(Add, Successor, (const Compliance& xs)) {
        Compliance ys(1.0);
        RC_ASSERT((xs + ys) != xs);
    }

    RC_GTEST_PROP(Mul, Associative, (const Compliance& xs, const Compliance& ys, const Compliance& zs)) {
        RC_ASSERT(((xs * ys) * zs) == (xs * ys * zs));
    }

    RC_GTEST_PROP(Mul, Commutative, (const Compliance& xs, const Compliance& ys)) {
        RC_ASSERT((xs * ys) == (ys * xs));
    }

    RC_GTEST_PROP(Mul, Neutral, (const Compliance& xs)) {
        Compliance ys(1.0);
        RC_ASSERT((xs * ys) == xs);
    }

    RC_GTEST_PROP(Mul, Zero, (const Compliance& xs)) {
        Compliance ys(0.0);
        RC_ASSERT((xs * ys) == ys);
    }

    RC_GTEST_PROP(Comparison, Greater, (const Compliance& xs)) {
        Compliance ys(1.0);
        RC_ASSERT((xs + ys) > xs);
        RC_ASSERT((xs + ys) >= xs);
    }

    RC_GTEST_PROP(Comparison, Lesser, (const Compliance& xs)) {
        Compliance ys(1.0);
        RC_ASSERT(xs <  (xs + ys));
        RC_ASSERT(xs <= (xs + ys));
    }
} // namespace f128

int
main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
