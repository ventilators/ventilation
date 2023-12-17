#include <gtest/gtest.h>
#include <rapidcheck/gtest.h>
#include <ventilation/ventilation.hpp>

#include "test-arbitrary.hpp"

// Tests single precision resistance implementation
namespace f32 {
    using Flow          = ventilation::Flow<float>;
    using Resistance    = ventilation::Resistance<float>;
    using Pressure      = ventilation::Pressure<float>;

    RC_GTEST_PROP(Add, Associative, (const Resistance& xs, const Resistance& ys, const Resistance& zs)) {
        RC_ASSERT(((xs + ys) + zs) == (xs + ys + zs));
    }

    RC_GTEST_PROP(Add, Commutative, (const Resistance& xs, const Resistance& ys)) {
        RC_ASSERT((xs + ys) == (ys + xs));
    }

    RC_GTEST_PROP(Add, Neutral, (const Resistance& xs)) {
        Resistance ys(0.0f);
        RC_ASSERT((xs + ys) == xs);
    }

    RC_GTEST_PROP(Add, Successor, (const Resistance& xs)) {
        Resistance ys(1.0f);
        RC_ASSERT((xs + ys) != xs);
    }

    RC_GTEST_PROP(Mul, Associative, (const Resistance& xs, const Resistance& ys, const Resistance& zs)) {
        RC_ASSERT(((xs * ys) * zs) == (xs * ys * zs));
    }

    RC_GTEST_PROP(Mul, Commutative, (const Resistance& xs, const Resistance& ys)) {
        RC_ASSERT((xs * ys) == (ys * xs));
    }

    RC_GTEST_PROP(Mul, Neutral, (const Resistance& xs)) {
        Resistance ys(1.0f);
        RC_ASSERT((xs * ys) == xs);
    }

    RC_GTEST_PROP(Mul, Zero, (const Resistance& xs)) {
        Resistance ys(0.0f);
        RC_ASSERT((xs * ys) == ys);
    }

    RC_GTEST_PROP(MulVolume, Commutative, (const Resistance& xs, const Flow& ys)) {
        RC_ASSERT((xs * ys) == (ys * xs));
    }

    RC_GTEST_PROP(MulVolume, Neutral, (const Resistance& xs)) {
        Flow ys(1.0f);
        RC_ASSERT((xs * ys) == (ys * xs));
    }

    RC_GTEST_PROP(MulVolume, Zero, (const Resistance& xs)) {
        Flow ys(0.0f);
        RC_ASSERT((xs * ys) == Pressure(0.0f));
    }

    RC_GTEST_PROP(Comparison, Greater, (const Resistance& xs)) {
        Resistance ys(1.0f);
        RC_ASSERT((xs + ys) > xs);
        RC_ASSERT((xs + ys) >= xs);
    }

    RC_GTEST_PROP(Comparison, Lesser, (const Resistance& xs)) {
        Resistance ys(1.0f);
        RC_ASSERT(xs <  (xs + ys));
        RC_ASSERT(xs <= (xs + ys));
    }
} // namespace f32 
// Tests double precision resistance implementation
namespace f64 {
    using Flow          = ventilation::Flow<double>;
    using Resistance    = ventilation::Resistance<double>;
    using Pressure      = ventilation::Pressure<double>;

    RC_GTEST_PROP(Add, Associative, (const Resistance& xs, const Resistance& ys, const Resistance& zs)) {
        RC_ASSERT(((xs + ys) + zs) == (xs + ys + zs));
    }

    RC_GTEST_PROP(Add, Commutative, (const Resistance& xs, const Resistance& ys)) {
        RC_ASSERT((xs + ys) == (ys + xs));
    }

    RC_GTEST_PROP(Add, Neutral, (const Resistance& xs)) {
        Resistance ys(0.0);
        RC_ASSERT((xs + ys) == xs);
    }

    RC_GTEST_PROP(Add, Successor, (const Resistance& xs)) {
        Resistance ys(1.0);
        RC_ASSERT((xs + ys) != xs);
    }

    RC_GTEST_PROP(Mul, Associative, (const Resistance& xs, const Resistance& ys, const Resistance& zs)) {
        RC_ASSERT(((xs * ys) * zs) == (xs * ys * zs));
    }

    RC_GTEST_PROP(Mul, Commutative, (const Resistance& xs, const Resistance& ys)) {
        RC_ASSERT((xs * ys) == (ys * xs));
    }

    RC_GTEST_PROP(Mul, Neutral, (const Resistance& xs)) {
        Resistance ys(1.0);
        RC_ASSERT((xs * ys) == xs);
    }

    RC_GTEST_PROP(Mul, Zero, (const Resistance& xs)) {
        Resistance ys(0.0);
        RC_ASSERT((xs * ys) == ys);
    }

    RC_GTEST_PROP(MulVolume, Commutative, (const Resistance& xs, const Flow& ys)) {
        RC_ASSERT((xs * ys) == (ys * xs));
    }

    RC_GTEST_PROP(MulVolume, Neutral, (const Resistance& xs)) {
        Flow ys(1.0);
        RC_ASSERT((xs * ys) == (ys * xs));
    }

    RC_GTEST_PROP(MulVolume, Zero, (const Resistance& xs)) {
        Flow ys(0.0);
        RC_ASSERT((xs * ys) == Pressure(0.0));
    }

    RC_GTEST_PROP(Comparison, Greater, (const Resistance& xs)) {
        Resistance ys(1.0);
        RC_ASSERT((xs + ys) > xs);
        RC_ASSERT((xs + ys) >= xs);
    }

    RC_GTEST_PROP(Comparison, Lesser, (const Resistance& xs)) {
        Resistance ys(1.0);
        RC_ASSERT(xs <  (xs + ys));
        RC_ASSERT(xs <= (xs + ys));
    }
} // namespace f64 
// Tests long double precision resistance implementation
namespace f128 {
    using Flow          = ventilation::Flow<long double>;
    using Resistance    = ventilation::Resistance<long double>;
    using Pressure      = ventilation::Pressure<long double>;

    RC_GTEST_PROP(Add, Associative, (const Resistance& xs, const Resistance& ys, const Resistance& zs)) {
        RC_ASSERT(((xs + ys) + zs) == (xs + ys + zs));
    }

    RC_GTEST_PROP(Add, Commutative, (const Resistance& xs, const Resistance& ys)) {
        RC_ASSERT((xs + ys) == (ys + xs));
    }

    RC_GTEST_PROP(Add, Neutral, (const Resistance& xs)) {
        Resistance ys(0.0);
        RC_ASSERT((xs + ys) == xs);
    }

    RC_GTEST_PROP(Add, Successor, (const Resistance& xs)) {
        Resistance ys(1.0);
        RC_ASSERT((xs + ys) != xs);
    }

    RC_GTEST_PROP(Mul, Associative, (const Resistance& xs, const Resistance& ys, const Resistance& zs)) {
        RC_ASSERT(((xs * ys) * zs) == (xs * ys * zs));
    }

    RC_GTEST_PROP(Mul, Commutative, (const Resistance& xs, const Resistance& ys)) {
        RC_ASSERT((xs * ys) == (ys * xs));
    }

    RC_GTEST_PROP(Mul, Neutral, (const Resistance& xs)) {
        Resistance ys(1.0);
        RC_ASSERT((xs * ys) == xs);
    }

    RC_GTEST_PROP(Mul, Zero, (const Resistance& xs)) {
        Resistance ys(0.0);
        RC_ASSERT((xs * ys) == ys);
    }

    RC_GTEST_PROP(MulVolume, Commutative, (const Resistance& xs, const Flow& ys)) {
        RC_ASSERT((xs * ys) == (ys * xs));
    }

    RC_GTEST_PROP(MulVolume, Neutral, (const Resistance& xs)) {
        Flow ys(1.0);
        RC_ASSERT((xs * ys) == (ys * xs));
    }

    RC_GTEST_PROP(MulVolume, Zero, (const Resistance& xs)) {
        Flow ys(0.0);
        RC_ASSERT((xs * ys) == Pressure(0.0));
    }

    RC_GTEST_PROP(Comparison, Greater, (const Resistance& xs)) {
        Resistance ys(1.0);
        RC_ASSERT((xs + ys) > xs);
        RC_ASSERT((xs + ys) >= xs);
    }

    RC_GTEST_PROP(Comparison, Lesser, (const Resistance& xs)) {
        Resistance ys(1.0);
        RC_ASSERT(xs <  (xs + ys));
        RC_ASSERT(xs <= (xs + ys));
    }
} // namespace f64 

int
main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
