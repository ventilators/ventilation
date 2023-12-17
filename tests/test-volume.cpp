#include <gtest/gtest.h>
#include <rapidcheck/gtest.h>
#include <ventilation/ventilation.hpp>

#include "test-arbitrary.hpp"

// Tests single precision volume implementation
namespace f32 {
    using Volume = ventilation::Volume<float>;
    RC_GTEST_PROP(Add, Associative, (const Volume& xs, const Volume& ys, const Volume& zs)) {
        RC_ASSERT(((xs + ys) + zs) == (xs + ys + zs));
    }

    RC_GTEST_PROP(Add, Commutative, (const Volume& xs, const Volume& ys)) {
        RC_ASSERT((xs + ys) == (ys + xs));
    }

    RC_GTEST_PROP(Add, Neutral, (const Volume& xs)) {
        Volume ys(0.0f);
        RC_ASSERT((xs + ys) == xs);
    }

    RC_GTEST_PROP(Add, Successor, (const Volume& xs)) {
        Volume ys(1.0f);
        RC_ASSERT((xs + ys) != xs);
    }

    RC_GTEST_PROP(Mul, Associative, (const Volume& xs, const Volume& ys, const Volume& zs)) {
        RC_ASSERT(((xs * ys) * zs) == (xs * ys * zs));
    }

    RC_GTEST_PROP(Mul, Commutative, (const Volume& xs, const Volume& ys)) {
        RC_ASSERT((xs * ys) == (ys * xs));
    }

    RC_GTEST_PROP(Mul, Neutral, (const Volume& xs)) {
        Volume ys(1.0f);
        RC_ASSERT((xs * ys) == xs);
    }

    RC_GTEST_PROP(Mul, Zero, (const Volume& xs)) {
        Volume ys(0.0f);
        RC_ASSERT((xs * ys) == ys);
    }

    RC_GTEST_PROP(MulScalar, Commutative, (const Volume& xs)) {
        float ys = *rc::gen::inRange(-100, 100);
        RC_ASSERT((xs * ys) == (ys * xs));
    }

    RC_GTEST_PROP(MulScalar, Neutral, (const Volume& xs)) {
        float ys = 1.0f;
        RC_ASSERT((xs * ys) == Volume(xs));
    }

    RC_GTEST_PROP(MulScalar, Zero, (const Volume& xs)) {
        float ys = 0.0f;
        RC_ASSERT((xs * ys) == Volume(ys));
    }

    RC_GTEST_PROP(Comparison, Greater, (const Volume& xs)) {
        Volume ys(1.0f);
        RC_ASSERT((xs + ys) >  xs);
        RC_ASSERT((xs + ys) >= xs);
    }

    RC_GTEST_PROP(Comparison, Lesser, (const Volume& xs)) {
        Volume ys(1.0f);
        RC_ASSERT(xs <  (xs + ys));
        RC_ASSERT(xs <= (xs + ys));
    }
} // namespace f32
namespace f64 {
    using Volume = ventilation::Volume<double>;
    RC_GTEST_PROP(Add, Associative, (const Volume& xs, const Volume& ys, const Volume& zs)) {
        RC_ASSERT(((xs + ys) + zs) == (xs + ys + zs));
    }

    RC_GTEST_PROP(Add, Commutative, (const Volume& xs, const Volume& ys)) {
        RC_ASSERT((xs + ys) == (ys + xs));
    }

    RC_GTEST_PROP(Add, Neutral, (const Volume& xs)) {
        Volume ys(0.0);
        RC_ASSERT((xs + ys) == xs);
    }

    RC_GTEST_PROP(Add, Successor, (const Volume& xs)) {
        Volume ys(1.0);
        RC_ASSERT((xs + ys) != xs);
    }

    RC_GTEST_PROP(Mul, Associative, (const Volume& xs, const Volume& ys, const Volume& zs)) {
        RC_ASSERT(((xs * ys) * zs) == (xs * ys * zs));
    }

    RC_GTEST_PROP(Mul, Commutative, (const Volume& xs, const Volume& ys)) {
        RC_ASSERT((xs * ys) == (ys * xs));
    }

    RC_GTEST_PROP(Mul, Neutral, (const Volume& xs)) {
        Volume ys(1.0);
        RC_ASSERT((xs * ys) == xs);
    }

    RC_GTEST_PROP(Mul, Zero, (const Volume& xs)) {
        Volume ys(0.0);
        RC_ASSERT((xs * ys) == ys);
    }

    RC_GTEST_PROP(MulScalar, Commutative, (const Volume& xs)) {
        double ys = *rc::gen::inRange(-100, 100);
        RC_ASSERT((xs * ys) == (ys * xs));
    }

    RC_GTEST_PROP(MulScalar, Neutral, (const Volume& xs)) {
        double ys = 1.0;
        RC_ASSERT((xs * ys) == Volume(xs));
    }

    RC_GTEST_PROP(MulScalar, Zero, (const Volume& xs)) {
        double ys = 0.0;
        RC_ASSERT((xs * ys) == Volume(ys));
    }

    RC_GTEST_PROP(Comparison, Greater, (const Volume& xs)) {
        Volume ys(1.0);
        RC_ASSERT((xs + ys) >  xs);
        RC_ASSERT((xs + ys) >= xs);
    }

    RC_GTEST_PROP(Comparison, Lesser, (const Volume& xs)) {
        Volume ys(1.0);
        RC_ASSERT(xs <  (xs + ys));
        RC_ASSERT(xs <= (xs + ys));
    }
} // namespace f64
namespace f128 {
    using Volume = ventilation::Volume<long double>;
    RC_GTEST_PROP(Add, Associative, (const Volume& xs, const Volume& ys, const Volume& zs)) {
        RC_ASSERT(((xs + ys) + zs) == (xs + ys + zs));
    }

    RC_GTEST_PROP(Add, Commutative, (const Volume& xs, const Volume& ys)) {
        RC_ASSERT((xs + ys) == (ys + xs));
    }

    RC_GTEST_PROP(Add, Neutral, (const Volume& xs)) {
        Volume ys(0.0);
        RC_ASSERT((xs + ys) == xs);
    }

    RC_GTEST_PROP(Add, Successor, (const Volume& xs)) {
        Volume ys(1.0);
        RC_ASSERT((xs + ys) != xs);
    }

    RC_GTEST_PROP(Mul, Associative, (const Volume& xs, const Volume& ys, const Volume& zs)) {
        RC_ASSERT(((xs * ys) * zs) == (xs * ys * zs));
    }

    RC_GTEST_PROP(Mul, Commutative, (const Volume& xs, const Volume& ys)) {
        RC_ASSERT((xs * ys) == (ys * xs));
    }

    RC_GTEST_PROP(Mul, Neutral, (const Volume& xs)) {
        Volume ys(1.0);
        RC_ASSERT((xs * ys) == xs);
    }

    RC_GTEST_PROP(Mul, Zero, (const Volume& xs)) {
        Volume ys(0.0);
        RC_ASSERT((xs * ys) == ys);
    }

    RC_GTEST_PROP(MulScalar, Commutative, (const Volume& xs)) {
        long double ys = *rc::gen::inRange(-100, 100);
        RC_ASSERT((xs * ys) == (ys * xs));
    }

    RC_GTEST_PROP(MulScalar, Neutral, (const Volume& xs)) {
        long double ys = 1.0;
        RC_ASSERT((xs * ys) == Volume(xs));
    }

    RC_GTEST_PROP(MulScalar, Zero, (const Volume& xs)) {
        long double ys = 0.0;
        RC_ASSERT((xs * ys) == Volume(ys));
    }

    RC_GTEST_PROP(Comparison, Greater, (const Volume& xs)) {
        Volume ys(1.0);
        RC_ASSERT((xs + ys) >  xs);
        RC_ASSERT((xs + ys) >= xs);
    }

    RC_GTEST_PROP(Comparison, Lesser, (const Volume& xs)) {
        Volume ys(1.0);
        RC_ASSERT(xs <  (xs + ys));
        RC_ASSERT(xs <= (xs + ys));
    }
} // namespace f64

int
main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
