#include <gtest/gtest.h>

#include <seqan3/align/align_config.hpp>

using namespace seqan3;

TEST( align_config_test, default_ctr )
{
    align_config config{};
    EXPECT_EQ( config.algorithm, align_enum::dynamic_config );
}

TEST( align_config_test, copy_ctr )
{
    size_t band_start = 5;
    size_t band_end = 10;
    align_config config{align_enum::local, band_start, band_end};

    EXPECT_EQ( config.algorithm, align_enum::local );
    EXPECT_EQ( config.band_start, 5 );
    EXPECT_EQ( config.band_end, 10 );
}

// ... move constructor, assignment

TEST( align_config_test, templated_default_ctr )
{
    align_config<align_enum::local> config{};

    EXPECT_EQ( config.algorithm, align_enum::local );
}

TEST( align_config_test, templated_copy_ctr )
{
    size_t band_start = 5;
    size_t band_end = 10;
    align_config<align_enum::local> config{band_start, band_end};

    EXPECT_EQ( config.algorithm, align_enum::local );
    EXPECT_EQ( config.band_start, 5 );
    EXPECT_EQ( config.band_end, 10 );
}

TEST( align_config_test, assign_band )
{
    align_config config{};
    config.band_start = 5;
    config.band_end = 10;

    EXPECT_EQ( config.band_start, 5 );
    EXPECT_EQ( config.band_end, 10 );
}

TEST( align_config_test, config_not_at_compile_time )
{
    align_config config{align_enum::local};

    constexpr bool at_compile_time = config.at_compile_time();
    EXPECT_FALSE( at_compile_time );
}

TEST( align_config_test, config_at_compile_time )
{
    align_config<align_enum::local> config{};

    constexpr bool at_compile_time = config.at_compile_time();
    EXPECT_TRUE( at_compile_time );
}
