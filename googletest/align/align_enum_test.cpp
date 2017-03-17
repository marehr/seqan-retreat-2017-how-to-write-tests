#include <gtest/gtest.h>

#include <seqan3/align/align_enum.hpp>

using namespace seqan3;

TEST( align_enum_test, align_enum_default_ctr )
{
    align_enum algorithm{};
    EXPECT_EQ( algorithm, align_enum::dynamic_config ); // continues on error
    // ASSERT_EQ( algorithm, align_enum::dynamic_config ); // throws on error
}

TEST( align_enum_test, align_enum_copy_ctr )
{
    auto algorithm = align_enum::local;
    EXPECT_EQ( algorithm, align_enum::local ); // continues on error
    // ASSERT_EQ( algorithm, align_enum::local ); // throws on error
}

TEST( align_enum_test, align_enum_move_ctr )
{
    auto algorithm1 = align_enum::local;
    auto algorithm2 = std::move(algorithm1);
    EXPECT_EQ( algorithm2, align_enum::local ); // continues on error
    // ASSERT_EQ( algorithm2, align_enum::local ); // throws on error
}

TEST( align_enum_test, align_enum_copy_assignment )
{
    align_enum algorithm{};
    algorithm = align_enum::global;
    EXPECT_EQ( algorithm, align_enum::global ); // continues on error
    // ASSERT_EQ( algorithm, align_enum::global ); // throws on error
}

TEST( align_enum_test, align_enum_move_assignment )
{
    auto algorithm1 = align_enum::global;
    auto algorithm2 = align_enum::local;
    algorithm2 = std::move(algorithm1);
    EXPECT_EQ( algorithm2, align_enum::global ); // continues on error
    // ASSERT_EQ( algorithm2, align_enum::global ); // throws on error
}

TEST( align_enum_test, align_enum_constexpr_ctr )
{
    constexpr auto algorithm = align_enum::semi_global;

    if constexpr(algorithm != align_enum::semi_global) {
        EXPECT_FALSE( true ) << "expected algorithm == align_enum::semi_global"; // continues on error
        // ASSERT_FALSE( true ) << "expected algorithm == align_enum::semi_global"; // throws on error

        EXPECT_EQ( algorithm, align_enum::semi_global ); // continues on error
        // ASSERT_EQ( algorithm, align_enum::semi_global ); // throws on error
    } else {
        EXPECT_EQ( algorithm, align_enum::semi_global ); // continues on error
        // ASSERT_EQ( algorithm, align_enum::semi_global ); // throws on error
    }
}
