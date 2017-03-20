#include <gtest/gtest.h>

using testing::Types;

template <typename int_type>
struct integral_types_test : public testing::Test
{
    using int_t = int_type;

    int_t value{5};
    static constexpr int_t shared{9};
};

using intergral_types = Types<int32_t, uint32_t, int8_t>;
TYPED_TEST_CASE(integral_types_test, intergral_types);

TYPED_TEST(integral_types_test, default_ctr)
{
    using int_t = typename TestFixture::int_t;
    int_t a{};

    EXPECT_EQ( a, 0 );
};

// other constructors

TYPED_TEST(integral_types_test, access_value)
{
    EXPECT_EQ( this->value, 5 );
};

TYPED_TEST(integral_types_test, access_static_shared)
{
    EXPECT_EQ( TestFixture::shared, 9 );
};

TYPED_TEST(integral_types_test, type_in_typed_test_case)
{
    using int_t = typename TestFixture::int_t;
    TypeParam a{5};

    static_assert(std::is_same_v<TypeParam, int_t>);
};

TYPED_TEST(integral_types_test, add) {
    using int_t = typename TestFixture::int_t;
    int_t a{3}, b{5};

    auto c = a+b;
    EXPECT_EQ( c, 8 );
}

TYPED_TEST(integral_types_test, sub) {
    using int_t = typename TestFixture::int_t;
    int_t a{3}, b{5};

    auto c = a-b;
    EXPECT_EQ( c, -2 );
}
