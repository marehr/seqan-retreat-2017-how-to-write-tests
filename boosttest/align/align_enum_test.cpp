#define BOOST_TEST_MODULE AlignConfigTest
#include <boost/test/unit_test.hpp>

#include <seqan3/align/align_enum.hpp>

using namespace seqan3;

BOOST_AUTO_TEST_CASE( align_enum_default_ctr )
{
    align_enum algorithm{};
    BOOST_CHECK_EQUAL( algorithm, align_enum::dynamic_config ); // continues on error
    // BOOST_REQUIRE_EQUAL( algorithm, align_enum::dynamic_config ); // throws on error
}

BOOST_AUTO_TEST_CASE( align_enum_copy_ctr )
{
    auto algorithm = align_enum::local;
    BOOST_CHECK_EQUAL( algorithm, align_enum::local ); // continues on error
    // BOOST_REQUIRE_EQUAL( algorithm, align_enum::local ); // throws on error
}

BOOST_AUTO_TEST_CASE( align_enum_move_ctr )
{
    auto algorithm1 = align_enum::local;
    auto algorithm2 = std::move(algorithm1);
    BOOST_CHECK_EQUAL( algorithm2, align_enum::local ); // continues on error
    // BOOST_REQUIRE_EQUAL( algorithm2, align_enum::local ); // throws on error
}

BOOST_AUTO_TEST_CASE( align_enum_copy_assignment )
{
    align_enum algorithm{};
    algorithm = align_enum::global;
    BOOST_CHECK_EQUAL( algorithm, align_enum::global ); // continues on error
    // BOOST_REQUIRE_EQUAL( algorithm, align_enum::global ); // throws on error
}

BOOST_AUTO_TEST_CASE( align_enum_move_assignment )
{
    auto algorithm1 = align_enum::global;
    auto algorithm2 = align_enum::local;
    algorithm2 = std::move(algorithm1);
    BOOST_CHECK_EQUAL( algorithm2, align_enum::global ); // continues on error
    // BOOST_REQUIRE_EQUAL( algorithm2, align_enum::global ); // throws on error
}

BOOST_AUTO_TEST_CASE( align_enum_constexpr_ctr )
{
    constexpr auto algorithm = align_enum::semi_global;

    if constexpr(algorithm != align_enum::semi_global) {
        BOOST_ERROR( "expected algorithm == align_enum::semi_global" ); // continues on error
        // BOOST_FAIL( "expected algorithm == align_enum::semi_global" ); // throws on error

        BOOST_CHECK_EQUAL( algorithm, align_enum::semi_global ); // continues on error
        // BOOST_REQUIRE_EQUAL( algorithm, align_enum::semi_global ); // throws on error
    } else {
        BOOST_CHECK_EQUAL( algorithm, align_enum::semi_global ); // continues on error
        // BOOST_REQUIRE_EQUAL( algorithm, align_enum::semi_global ); // throws on error
    }
}
