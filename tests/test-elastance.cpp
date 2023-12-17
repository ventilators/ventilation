#include <gtest/gtest.h>
#include <rapidcheck/gtest.h>
#include <ventilation/ventilation.hpp>

#include "test-arbitrary.hpp"

// Tests single precision elastance implementation
namespace f32 {
    using Elastance = ventilation::Elastance<float>;
    using Pressure  = ventilation::Pressure<float>;
    using Volume    = ventilation::Volume<float>;

    RC_GTEST_PROP(Add, Associative, (const Elastance& xs, const Elastance& ys, const Elastance& zs)) {
        RC_ASSERT(((xs + ys) + zs) == (xs + ys + zs));
    }

    RC_GTEST_PROP(Add, Commutative, (const Elastance& xs, const Elastance& ys)) {
        RC_ASSERT((xs + ys) == (ys + xs));
    }

    RC_GTEST_PROP(Add, Neutral, (const Elastance& xs)) {
        Elastance ys(0.0f);
        RC_ASSERT((xs + ys) == xs);
    }

    RC_GTEST_PROP(Add, Successor, (const Elastance& xs)) {
        Elastance ys(1.0f);
        RC_ASSERT((xs + ys) != xs);
    }

    RC_GTEST_PROP(Mul, Associative, (const Elastance& xs, const Elastance& ys, const Elastance& zs)) {
        RC_ASSERT(((xs * ys) * zs) == (xs * ys * zs));
    }

    RC_GTEST_PROP(Mul, Commutative, (const Elastance& xs, const Elastance& ys)) {
        RC_ASSERT((xs * ys) == (ys * xs));
    }

    RC_GTEST_PROP(Mul, Neutral, (const Elastance& xs)) {
        Elastance ys(1.0f);
        RC_ASSERT((xs * ys) == xs);
    }

    RC_GTEST_PROP(Mul, Zero, (const Elastance& xs)) {
        Elastance ys(0.0f);
        RC_ASSERT((xs * ys) == ys);
    }

    RC_GTEST_PROP(MulScalar, Neutral, (const Elastance& xs)) {
        float ys = 1.0f;
        RC_ASSERT((xs * ys) == Elastance(xs));
    }

    RC_GTEST_PROP(MulScalar, Zero, (const Elastance& xs)) {
        float ys = 0.0f;
        RC_ASSERT((xs * ys) == Elastance(ys));
    }

    RC_GTEST_PROP(MulVolume, Commutative, (const Elastance& xs, const Volume& ys)) {
        RC_ASSERT((xs * ys) == (ys * xs));
    }

    RC_GTEST_PROP(MulVolume, Neutral, (const Elastance& xs)) {
        Volume ys(1.0f);
        RC_ASSERT((xs * ys) == (ys * xs));
    }

    RC_GTEST_PROP(MulVolume, Zero, (const Elastance& xs)) {
        Volume ys(0.0f);
        RC_ASSERT((xs * ys) == Pressure(0.0f));
    }
} // namespace f32
// Tests double precision elastance implementation
namespace f64 {
    using Elastance = ventilation::Elastance<double>;
    using Pressure  = ventilation::Pressure<double>;
    using Volume    = ventilation::Volume<double>;

    RC_GTEST_PROP(Add, Associative, (const Elastance& xs, const Elastance& ys, const Elastance& zs)) {
        RC_ASSERT(((xs + ys) + zs) == (xs + ys + zs));
    }

    RC_GTEST_PROP(Add, Commutative, (const Elastance& xs, const Elastance& ys)) {
        RC_ASSERT((xs + ys) == (ys + xs));
    }

    RC_GTEST_PROP(Add, Neutral, (const Elastance& xs)) {
        Elastance ys(0.0);
        RC_ASSERT((xs + ys) == xs);
    }

    RC_GTEST_PROP(Add, Successor, (const Elastance& xs)) {
        Elastance ys(1.0);
        RC_ASSERT((xs + ys) != xs);
    }

    RC_GTEST_PROP(Mul, Associative, (const Elastance& xs, const Elastance& ys, const Elastance& zs)) {
        RC_ASSERT(((xs * ys) * zs) == (xs * ys * zs));
    }

    RC_GTEST_PROP(Mul, Commutative, (const Elastance& xs, const Elastance& ys)) {
        RC_ASSERT((xs * ys) == (ys * xs));
    }

    RC_GTEST_PROP(Mul, Neutral, (const Elastance& xs)) {
        Elastance ys(1.0);
        RC_ASSERT((xs * ys) == xs);
    }

    RC_GTEST_PROP(Mul, Zero, (const Elastance& xs)) {
        Elastance ys(0.0);
        RC_ASSERT((xs * ys) == ys);
    }

    RC_GTEST_PROP(MulScalar, Neutral, (const Elastance& xs)) {
        double ys = 1.0;
        RC_ASSERT((xs * ys) == Elastance(xs));
    }

    RC_GTEST_PROP(MulScalar, Zero, (const Elastance& xs)) {
        double ys = 0.0;
        RC_ASSERT((xs * ys) == Elastance(ys));
    }

    RC_GTEST_PROP(MulVolume, Commutative, (const Elastance& xs, const Volume& ys)) {
        RC_ASSERT((xs * ys) == (ys * xs));
    }

    RC_GTEST_PROP(MulVolume, Neutral, (const Elastance& xs)) {
        Volume ys(1.0);
        RC_ASSERT((xs * ys) == (ys * xs));
    }

    RC_GTEST_PROP(MulVolume, Zero, (const Elastance& xs)) {
        Volume ys(0.0);
        RC_ASSERT((xs * ys) == Pressure(0.0));
    }
} // namespace f64
// Tests long double precision elastance implementation
namespace f128 {
    using Elastance = ventilation::Elastance<long double>;
    using Pressure  = ventilation::Pressure<long double>;
    using Volume    = ventilation::Volume<long double>;

    RC_GTEST_PROP(Add, Associative, (const Elastance& xs, const Elastance& ys, const Elastance& zs)) {
        RC_ASSERT(((xs + ys) + zs) == (xs + ys + zs));
    }

    RC_GTEST_PROP(Add, Commutative, (const Elastance& xs, const Elastance& ys)) {
        RC_ASSERT((xs + ys) == (ys + xs));
    }

    RC_GTEST_PROP(Add, Neutral, (const Elastance& xs)) {
        Elastance ys(0.0);
        RC_ASSERT((xs + ys) == xs);
    }

    RC_GTEST_PROP(Add, Successor, (const Elastance& xs)) {
        Elastance ys(1.0);
        RC_ASSERT((xs + ys) != xs);
    }

    RC_GTEST_PROP(Mul, Associative, (const Elastance& xs, const Elastance& ys, const Elastance& zs)) {
        RC_ASSERT(((xs * ys) * zs) == (xs * ys * zs));
    }

    RC_GTEST_PROP(Mul, Commutative, (const Elastance& xs, const Elastance& ys)) {
        RC_ASSERT((xs * ys) == (ys * xs));
    }

    RC_GTEST_PROP(Mul, Neutral, (const Elastance& xs)) {
        Elastance ys(1.0);
        RC_ASSERT((xs * ys) == xs);
    }

    RC_GTEST_PROP(Mul, Zero, (const Elastance& xs)) {
        Elastance ys(0.0);
        RC_ASSERT((xs * ys) == ys);
    }

    RC_GTEST_PROP(MulScalar, Neutral, (const Elastance& xs)) {
        double ys = 1.0;
        RC_ASSERT((xs * ys) == Elastance(xs));
    }

    RC_GTEST_PROP(MulScalar, Zero, (const Elastance& xs)) {
        double ys = 0.0;
        RC_ASSERT((xs * ys) == Elastance(ys));
    }

    RC_GTEST_PROP(MulVolume, Commutative, (const Elastance& xs, const Volume& ys)) {
        RC_ASSERT((xs * ys) == (ys * xs));
    }

    RC_GTEST_PROP(MulVolume, Neutral, (const Elastance& xs)) {
        Volume ys(1.0);
        RC_ASSERT((xs * ys) == (ys * xs));
    }

    RC_GTEST_PROP(MulVolume, Zero, (const Elastance& xs)) {
        Volume ys(0.0);
        RC_ASSERT((xs * ys) == Pressure(0.0));
    }
} // namespace f128

int
main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
