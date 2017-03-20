#include <gtest/gtest.h>

using testing::Types;

template <typename int_type>
struct integral_types_test : public testing::Test
{
    using int_t = int_type;

    int_t value{5};
    static constexpr int_t shared{9};
};

// TODO: add more types to test
using integral_types = Types<uint8_t, int8_t>;
TYPED_TEST_CASE(integral_types_test, integral_types);

// ===
// constructors
// ===

TYPED_TEST(integral_types_test, default_ctr)
{
    using int_t = typename TestFixture::int_t;
    int_t a{};

    EXPECT_EQ( a, 0 );
}

// ... other constructors

// ===
// accessing fixture members
// ===

TYPED_TEST(integral_types_test, access_value)
{
    EXPECT_EQ( this->value, 5 );
}

TYPED_TEST(integral_types_test, access_static_shared)
{
    EXPECT_EQ( TestFixture::shared, 9 );
}

TYPED_TEST(integral_types_test, type_in_typed_test_case)
{
    using int_t = typename TestFixture::int_t;
    TypeParam a{5};

    static_assert(std::is_same_v<TypeParam, int_t>);
}

// ===
// EXPECT_* variants
// ===

TYPED_TEST(integral_types_test, eq)
{
    using int_t = typename TestFixture::int_t;
    int_t a{5}, b{5};

    EXPECT_EQ( a, b ); // a == b continues on error
    // ASSERT_EQ( a, b ); // a == b throws on error
}

TYPED_TEST(integral_types_test, ne)
{
    using int_t = typename TestFixture::int_t;
    int_t a{3}, b{5};

    EXPECT_NE( a, b ); // a != b continues on error
    // ASSERT_NE( a, b ); // a != b throws on error
}

TYPED_TEST(integral_types_test, lt)
{
    using int_t = typename TestFixture::int_t;
    int_t a{3}, b{5};

    EXPECT_LT( a, b ); // a < b continues on error
    // ASSERT_LT( a, b ); // a < b throws on error
}

TYPED_TEST(integral_types_test, le)
{
    using int_t = typename TestFixture::int_t;
    int_t a{3}, b{5};
    int_t c{5}, d{5};

    EXPECT_LE( a, b ); // a <= b continues on error
    // ASSERT_LE( a, b ); // a <= b throws on error
    EXPECT_GE( c, d ); // c <= d continues on error
    // ASSERT_GE( c, d ); // c <= d throws on error
}

TYPED_TEST(integral_types_test, gt)
{
    using int_t = typename TestFixture::int_t;
    int_t a{5}, b{3};

    EXPECT_GT( a, b ); // a > b continues on error
    // ASSERT_GT( a, b ); // a > b throws on error
}

TYPED_TEST(integral_types_test, ge)
{
    using int_t = typename TestFixture::int_t;
    int_t a{5}, b{3};
    int_t c{5}, d{5};

    EXPECT_GE( a, b ); // a >= b continues on error
    // ASSERT_GE( a, b ); // a >= b throws on error
    EXPECT_GE( c, d ); // c >= d continues on error
    // ASSERT_GE( c, d ); // c >= d throws on error
}

// ===
// operator tests
// ===

TYPED_TEST(integral_types_test, add)
{
    using int_t = typename TestFixture::int_t;
    int_t a{3}, b{5};

    auto c = a+b;
    EXPECT_EQ( c, 8 );
}

TYPED_TEST(integral_types_test, sub)
{
    using int_t = typename TestFixture::int_t;
    int_t a{3}, b{5};

    auto c = a-b;
    EXPECT_EQ( c, -2 ); // c - 2
}

// TODO: add more operator test cases

// ===
// custom functions
// ===

template <typename T>
constexpr bool is_power_of_two(T a)
{
    return a == 0 || ((a-1) & a) == 0;
}

TYPED_TEST(integral_types_test, is_power_of_two)
{
    using int_t = typename TestFixture::int_t;

    EXPECT_TRUE( is_power_of_two(int_t{0}) );
    EXPECT_TRUE( is_power_of_two(int_t{1}) );
    EXPECT_TRUE( is_power_of_two(int_t{2}) );
    EXPECT_FALSE( is_power_of_two(int_t{3}) );
    EXPECT_TRUE( is_power_of_two(int_t{4}) );
    EXPECT_FALSE( is_power_of_two(int_t{5}) );
    EXPECT_FALSE( is_power_of_two(int_t{6}) );

    // Reference: 4.7 [conv.integral] / 4: If the source type is bool... true is converted to one
    constexpr int_t max_bits = 8*sizeof(int_t) - std::is_signed_v<int_t>;

    // every power of two in the range [1, max_value)
    for(int_t i = 0, j = 1; i < max_bits; ++i, j = 1 << i)
        EXPECT_TRUE( is_power_of_two(j) ) << +i << ". " << +j << " should be a power of two";

    // every other number in the range [3, max_value)
    for(int_t i = 1; i < max_bits; ++i)
        for(int_t j = (1 << i) + 1, k = (j - 2) + j; j < k; ++j)
            EXPECT_FALSE( is_power_of_two(j) ) << +i << ". " << +j << " shouldn't be a power of two";
}
