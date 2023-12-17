#include <gtest/gtest.h>
#include <rapidcheck/gtest.h>
#include <ventilation/ventilation.hpp>

#include "test-arbitrary.hpp"

// Tests single precision flow implementation
namespace f32 {
    using Flow = ventilation::Flow<float>;
    RC_GTEST_PROP(Add, Associative, (const Flow& xs, const Flow& ys, const Flow& zs)) {
        RC_ASSERT(((xs + ys) + zs) == (xs + ys + zs));
    }

    RC_GTEST_PROP(Add, Commutative, (const Flow& xs, const Flow& ys)) {
        RC_ASSERT((xs + ys) == (ys + xs));
    }

    RC_GTEST_PROP(Add, Neutral, (const Flow& xs)) {
        Flow ys(0.0f);
        RC_ASSERT((xs + ys) == xs);
    }

    RC_GTEST_PROP(Add, Successor, (const Flow& xs)) {
        Flow ys(1.0f);
        RC_ASSERT((xs + ys) != xs);
    }

    RC_GTEST_PROP(Mul, Associative, (const Flow& xs, const Flow& ys, const Flow& zs)) {
        RC_ASSERT(((xs * ys) * zs) == (xs * ys * zs));
    }

    RC_GTEST_PROP(Mul, Commutative, (const Flow& xs, const Flow& ys)) {
        RC_ASSERT((xs * ys) == (ys * xs));
    }

    RC_GTEST_PROP(Mul, Neutral, (const Flow& xs)) {
        Flow ys(1.0f);
        RC_ASSERT((xs * ys) == xs);
    }

    RC_GTEST_PROP(Mul, Zero, (const Flow& xs)) {
        Flow ys(0.0f);
        RC_ASSERT((xs * ys) == ys);
    }

    RC_GTEST_PROP(MulScalar, Neutral, (const Flow& xs)) {
        float ys = 1.0f;
        RC_ASSERT((xs * ys) == Flow(xs));
    }

    RC_GTEST_PROP(MulScalar, Zero, (const Flow& xs)) {
        float ys = 0.0f;
        RC_ASSERT((xs * ys) == Flow(ys));
    }

    RC_GTEST_PROP(Comparison, Greater, (const Flow& xs)) {
        Flow ys(1.0f);
        RC_ASSERT((xs + ys) >  xs);
        RC_ASSERT((xs + ys) >= xs);
    }

    RC_GTEST_PROP(Comparison, Lesser, (const Flow& xs)) {
        Flow ys(1.0f);
        RC_ASSERT(xs <  (xs + ys));
        RC_ASSERT(xs <= (xs + ys));
    }
} // namespace f32
// Tests double precision flow implementation
namespace f64 {
    using Flow = ventilation::Flow<double>;
    RC_GTEST_PROP(Add, Associativef64, (const Flow& xs, const Flow& ys, const Flow& zs)) {
        RC_ASSERT(((xs + ys) + zs) == (xs + ys + zs));
    }

    RC_GTEST_PROP(Add, Commutativef64, (const Flow& xs, const Flow& ys)) {
        RC_ASSERT((xs + ys) == (ys + xs));
    }

    RC_GTEST_PROP(Add, Neutralf64, (const Flow& xs)) {
        Flow ys(0.0);
        RC_ASSERT((xs + ys) == xs);
    }

    RC_GTEST_PROP(Add, Successorf64, (const Flow& xs)) {
        Flow ys(1.0);
        RC_ASSERT((xs + ys) != xs);
    }

    RC_GTEST_PROP(Mul, Associativef64, (const Flow& xs, const Flow& ys, const Flow& zs)) {
        RC_ASSERT(((xs * ys) * zs) == (xs * ys * zs));
    }

    RC_GTEST_PROP(Mul, Commutativef64, (const Flow& xs, const Flow& ys)) {
        RC_ASSERT((xs * ys) == (ys * xs));
    }

    RC_GTEST_PROP(Mul, Neutralf64, (const Flow& xs)) {
        Flow ys(1.0f);
        RC_ASSERT((xs * ys) == xs);
    }

    RC_GTEST_PROP(Mul, Zerof64, (const Flow& xs)) {
        Flow ys(0.0f);
        RC_ASSERT((xs * ys) == ys);
    }

    RC_GTEST_PROP(MulScalar, Neutralf64, (const Flow& xs)) {
        double ys = 1.0;
        RC_ASSERT((xs * ys) == Flow(xs));
    }

    RC_GTEST_PROP(MulScalar, Zerof64, (const Flow& xs)) {
        double ys = 0.0;
        RC_ASSERT((xs * ys) == Flow(ys));
    }

    RC_GTEST_PROP(Comparison, Greaterf64, (const Flow& xs)) {
        Flow ys(1.0);
        RC_ASSERT((xs + ys) >  xs);
        RC_ASSERT((xs + ys) >= xs);
    }

    RC_GTEST_PROP(Comparison, Lesserf64, (const Flow& xs)) {
        Flow ys(1.0);
        RC_ASSERT(xs <  (xs + ys));
        RC_ASSERT(xs <= (xs + ys));
    }
} // namespace f64
// Tests long double precision flow implementation
namespace f128 {
    using Flow = ventilation::Flow<float>;
    RC_GTEST_PROP(Add, Associative, (const Flow& xs, const Flow& ys, const Flow& zs)) {
        RC_ASSERT(((xs + ys) + zs) == (xs + ys + zs));
    }

    RC_GTEST_PROP(Add, Commutative, (const Flow& xs, const Flow& ys)) {
        RC_ASSERT((xs + ys) == (ys + xs));
    }

    RC_GTEST_PROP(Add, Neutral, (const Flow& xs)) {
        Flow ys(0.0);
        RC_ASSERT((xs + ys) == xs);
    }

    RC_GTEST_PROP(Add, Successor, (const Flow& xs)) {
        Flow ys(1.0);
        RC_ASSERT((xs + ys) != xs);
    }

    RC_GTEST_PROP(Mul, Associative, (const Flow& xs, const Flow& ys, const Flow& zs)) {
        RC_ASSERT(((xs * ys) * zs) == (xs * ys * zs));
    }

    RC_GTEST_PROP(Mul, Commutative, (const Flow& xs, const Flow& ys)) {
        RC_ASSERT((xs * ys) == (ys * xs));
    }

    RC_GTEST_PROP(Mul, Neutral, (const Flow& xs)) {
        Flow ys(1.0);
        RC_ASSERT((xs * ys) == xs);
    }

    RC_GTEST_PROP(Mul, Zero, (const Flow& xs)) {
        Flow ys(0.0);
        RC_ASSERT((xs * ys) == ys);
    }

    RC_GTEST_PROP(MulScalar, Neutral, (const Flow& xs)) {
        long double ys = 1.0;
        RC_ASSERT((xs * ys) == Flow(xs));
    }

    RC_GTEST_PROP(MulScalar, Zero, (const Flow& xs)) {
        long double ys = 0.0;
        RC_ASSERT((xs * ys) == Flow(ys));
    }

    RC_GTEST_PROP(Comparison, Greater, (const Flow& xs)) {
        Flow ys(1.0);
        RC_ASSERT((xs + ys) >  xs);
        RC_ASSERT((xs + ys) >= xs);
    }

    RC_GTEST_PROP(Comparison, Lesser, (const Flow& xs)) {
        Flow ys(1.0);
        RC_ASSERT(xs <  (xs + ys));
        RC_ASSERT(xs <= (xs + ys));
    }
} // namespace f128

int
main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
