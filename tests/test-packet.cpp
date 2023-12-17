#include <gtest/gtest.h>
#include <rapidcheck/gtest.h>
#include <ventilation/ventilation.hpp>

#include "test-arbitrary.hpp"

// Tests single precision packet implementation
namespace f32 {
    using Packet = ventilation::Packet<float>;
    RC_GTEST_PROP(Add, Associative, (const Packet& xs, const Packet& ys, const Packet& zs)) {
        RC_ASSERT(((xs + ys) + zs) == (xs + ys + zs));
    }

    RC_GTEST_PROP(Add, Commutative, (const Packet& xs, const Packet& ys)) {
        RC_ASSERT((xs + ys) == (ys + xs));
    }

    RC_GTEST_PROP(Add, Neutral, (const Packet& xs)) {
        Packet ys{ventilation::Flow(0.0f), ventilation::Pressure(0.0f), ventilation::Volume(0.0f)};
        RC_ASSERT((xs + ys) == xs);
    }

    RC_GTEST_PROP(Add, Successor, (const Packet& xs)) {
        Packet ys{ventilation::Flow(1.0f), ventilation::Pressure(1.0f), ventilation::Volume(1.0f)};
        RC_ASSERT((xs + ys) != xs);
    }

    RC_GTEST_PROP(Mul, Associative, (const Packet& xs, const Packet& ys, const Packet& zs)) {
        RC_ASSERT(((xs * ys) * zs) == (xs * ys * zs));
    }

    RC_GTEST_PROP(Mul, Commutative, (const Packet& xs, const Packet& ys)) {
        RC_ASSERT((xs * ys) == (ys * xs));
    }

    RC_GTEST_PROP(Mul, Neutral, (const Packet& xs)) {
        Packet ys{ventilation::Flow(1.0f), ventilation::Pressure(1.0f), ventilation::Volume(1.0f)};
        RC_ASSERT((xs * ys) == xs);
    }

    RC_GTEST_PROP(Mul, Zero, (const Packet& xs)) {
        Packet ys{ventilation::Flow(0.0f), ventilation::Pressure(0.0f), ventilation::Volume(0.0f)};
        RC_ASSERT((xs * ys) == ys);
    }

    RC_GTEST_PROP(MulScalar, Commutative, (const Packet& xs)) {
        float ys = *rc::gen::inRange(-100, 100);
        RC_ASSERT((xs * ys) == (ys * xs));
    }

    RC_GTEST_PROP(MulScalar, Neutral, (const Packet& xs)) {
        float y = 1.0f;
        RC_ASSERT((xs * y) == xs);
    }

    RC_GTEST_PROP(MulScalar, Zero, (const Packet& xs)) {
        float y = 0.0f;
        Packet ys{ventilation::Flow(y), ventilation::Pressure(y), ventilation::Volume(y)};
        RC_ASSERT((xs * y) == Packet(ys));
    }
} // namespace f32
// Tests double precision packet implementation
namespace f64 {
    using Packet = ventilation::Packet<double>;
    RC_GTEST_PROP(Add, Associative, (const Packet& xs, const Packet& ys, const Packet& zs)) {
        RC_ASSERT(((xs + ys) + zs) == (xs + ys + zs));
    }

    RC_GTEST_PROP(Add, Commutative, (const Packet& xs, const Packet& ys)) {
        RC_ASSERT((xs + ys) == (ys + xs));
    }

    RC_GTEST_PROP(Add, Neutral, (const Packet& xs)) {
        Packet ys{ventilation::Flow(0.0), ventilation::Pressure(0.0), ventilation::Volume(0.0)};
        RC_ASSERT((xs + ys) == xs);
    }

    RC_GTEST_PROP(Add, Successor, (const Packet& xs)) {
        Packet ys{ventilation::Flow(1.0), ventilation::Pressure(1.0), ventilation::Volume(1.0)};
        RC_ASSERT((xs + ys) != xs);
    }

    RC_GTEST_PROP(Mul, Associative, (const Packet& xs, const Packet& ys, const Packet& zs)) {
        RC_ASSERT(((xs * ys) * zs) == (xs * ys * zs));
    }

    RC_GTEST_PROP(Mul, Commutative, (const Packet& xs, const Packet& ys)) {
        RC_ASSERT((xs * ys) == (ys * xs));
    }

    RC_GTEST_PROP(Mul, Neutral, (const Packet& xs)) {
        Packet ys{ventilation::Flow(1.0), ventilation::Pressure(1.0), ventilation::Volume(1.0)};
        RC_ASSERT((xs * ys) == xs);
    }

    RC_GTEST_PROP(Mul, Zero, (const Packet& xs)) {
        Packet ys{ventilation::Flow(0.0), ventilation::Pressure(0.0), ventilation::Volume(0.0)};
        RC_ASSERT((xs * ys) == ys);
    }

    RC_GTEST_PROP(MulScalar, Commutative, (const Packet& xs)) {
        double ys = *rc::gen::inRange(-100, 100);
        RC_ASSERT((xs * ys) == (ys * xs));
    }

    RC_GTEST_PROP(MulScalar, Neutral, (const Packet& xs)) {
        double y = 1.0;
        RC_ASSERT((xs * y) == xs);
    }

    RC_GTEST_PROP(MulScalar, Zero, (const Packet& xs)) {
        double y = 0.0;
        Packet ys{ventilation::Flow(y), ventilation::Pressure(y), ventilation::Volume(y)};
        RC_ASSERT((xs * y) == Packet(ys));
    }
} // namespace f64
// Tests long double precision packet implementation
namespace f128 {
    using Packet = ventilation::Packet<double>;
    RC_GTEST_PROP(Add, Associative, (const Packet& xs, const Packet& ys, const Packet& zs)) {
        RC_ASSERT(((xs + ys) + zs) == (xs + ys + zs));
    }

    RC_GTEST_PROP(Add, Commutative, (const Packet& xs, const Packet& ys)) {
        RC_ASSERT((xs + ys) == (ys + xs));
    }

    RC_GTEST_PROP(Add, Neutral, (const Packet& xs)) {
        Packet ys{ventilation::Flow(0.0), ventilation::Pressure(0.0), ventilation::Volume(0.0)};
        RC_ASSERT((xs + ys) == xs);
    }

    RC_GTEST_PROP(Add, Successor, (const Packet& xs)) {
        Packet ys{ventilation::Flow(1.0), ventilation::Pressure(1.0), ventilation::Volume(1.0)};
        RC_ASSERT((xs + ys) != xs);
    }

    RC_GTEST_PROP(Mul, Associative, (const Packet& xs, const Packet& ys, const Packet& zs)) {
        RC_ASSERT(((xs * ys) * zs) == (xs * ys * zs));
    }

    RC_GTEST_PROP(Mul, Commutative, (const Packet& xs, const Packet& ys)) {
        RC_ASSERT((xs * ys) == (ys * xs));
    }

    RC_GTEST_PROP(Mul, Neutral, (const Packet& xs)) {
        Packet ys{ventilation::Flow(1.0), ventilation::Pressure(1.0), ventilation::Volume(1.0)};
        RC_ASSERT((xs * ys) == xs);
    }

    RC_GTEST_PROP(Mul, Zero, (const Packet& xs)) {
        Packet ys{ventilation::Flow(0.0), ventilation::Pressure(0.0), ventilation::Volume(0.0)};
        RC_ASSERT((xs * ys) == ys);
    }

    RC_GTEST_PROP(MulScalar, Commutative, (const Packet& xs)) {
        double ys = *rc::gen::inRange(-100, 100);
        RC_ASSERT((xs * ys) == (ys * xs));
    }

    RC_GTEST_PROP(MulScalar, Neutral, (const Packet& xs)) {
        double y = 1.0;
        RC_ASSERT((xs * y) == xs);
    }

    RC_GTEST_PROP(MulScalar, Zero, (const Packet& xs)) {
        double y = 0.0;
        Packet ys{ventilation::Flow(y), ventilation::Pressure(y), ventilation::Volume(y)};
        RC_ASSERT((xs * y) == Packet(ys));
    }
} // namespace f128

int
main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
