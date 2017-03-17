#pragma once

#include <iostream>

namespace seqan3 {

enum class align_enum : uint32_t {
    dynamic_config = 0,

    // algorithms
    global = 1 << 0,
    semi_global = 1 << 1,
    overlap = 1 << 2,
    dynamic_free_end_gaps = 1 << 3,
    local = 1 << 4,
    sub_optimal = 1 << 5,

    // gap_penalty models
    linear = 1 << 6,
    affine = 1 << 7,
    dynamic = 1 << 8,
    automatic = 1 << 9,

    // traceback
    one_best_gaps_left = 1 << 10,
    one_best_gaps_right = 1 << 11,
    all_best_gaps_left = 1 << 12,
    all_best_gaps_right = 1 << 13,

    // band
    off = 1 << 14,
    simple = 1 << 15,

    // output_format
    view_constant_access = 1 << 16,
    view_logarithmic_access = 1 << 17,
    view_linear_access = 1 << 18,
    graph = 1 << 19,
    segments = 1 << 20,
    score_only = 1 << 21
};

constexpr align_enum operator |(const align_enum& lhs, const align_enum& rhs)
{
    using uint_t = std::underlying_type_t<align_enum>;
    return align_enum{static_cast<uint_t>(lhs) | static_cast<uint_t>(rhs)};
}

constexpr align_enum operator &(const align_enum& lhs, const align_enum& rhs)
{
    using uint_t = std::underlying_type_t<align_enum>;
    return align_enum{static_cast<uint_t>(lhs) & static_cast<uint_t>(rhs)};
}

std::ostream & operator<<(std::ostream & out, align_enum const & algorithm)
{
    if(algorithm == align_enum::dynamic_config) {
        out << "dynamic_config";
        return out;
    }

    // algorithms
    if((algorithm & align_enum::global) == align_enum::global)
        out << "global, ";
    if((algorithm & align_enum::semi_global) == align_enum::semi_global)
        out << "semi_global, ";
    if((algorithm & align_enum::overlap) == align_enum::overlap)
        out << "overlap, ";
    if((algorithm & align_enum::dynamic_free_end_gaps) == align_enum::dynamic_free_end_gaps)
        out << "dynamic_free_end_gaps, ";
    if((algorithm & align_enum::local) == align_enum::local)
        out << "local, ";
    if((algorithm & align_enum::sub_optimal) == align_enum::sub_optimal)
        out << "sub_optimal, ";

    // gap_penalty models
    if((algorithm & align_enum::linear) == align_enum::linear)
        out << "linear, ";
    if((algorithm & align_enum::affine) == align_enum::affine)
        out << "affine, ";
    if((algorithm & align_enum::dynamic) == align_enum::dynamic)
        out << "dynamic, ";
    if((algorithm & align_enum::automatic) == align_enum::automatic)
        out << "automatic, ";

    // traceback
    if((algorithm & align_enum::one_best_gaps_left) == align_enum::one_best_gaps_left)
        out << "one_best_gaps_left, ";
    if((algorithm & align_enum::one_best_gaps_right) == align_enum::one_best_gaps_right)
        out << "one_best_gaps_right, ";
    if((algorithm & align_enum::all_best_gaps_left) == align_enum::all_best_gaps_left)
        out << "all_best_gaps_left, ";
    if((algorithm & align_enum::all_best_gaps_right) == align_enum::all_best_gaps_right)
        out << "all_best_gaps_right, ";

    // band
    if((algorithm & align_enum::off) == align_enum::off)
        out << "off, ";
    if((algorithm & align_enum::simple) == align_enum::simple)
        out << "simple, ";

    // output_format
    if((algorithm & align_enum::view_constant_access) == align_enum::view_constant_access)
        out << "view_constant_access, ";
    if((algorithm & align_enum::view_logarithmic_access) == align_enum::view_logarithmic_access)
        out << "view_logarithmic_access, ";
    if((algorithm & align_enum::view_linear_access) == align_enum::view_linear_access)
        out << "view_linear_access, ";
    if((algorithm & align_enum::graph) == align_enum::graph)
        out << "graph, ";
    if((algorithm & align_enum::segments) == align_enum::segments)
        out << "segments, ";
    if((algorithm & align_enum::score_only) == align_enum::score_only)
        out << "score_only, ";

    return out;
}

}
