#pragma once

#include "align_enum.hpp"

namespace seqan3 {

struct align_config_runtime {
    size_t band_start{};
    size_t band_end{};
};

template <align_enum algorithm_v>
struct align_config : align_config_runtime {
    constexpr static align_enum algorithm = algorithm_v;

    constexpr bool at_compile_time() {
        return true;
    }
};

template<>
struct align_config<align_enum::dynamic_config> : align_config_runtime {
    align_enum algorithm{};

    align_config() = default;
    align_config(align_enum algorithm) : algorithm{algorithm}{}

    constexpr bool at_compile_time() {
        return false;
    }
};

align_config(align_enum) -> align_config<align_enum::dynamic_config>;
align_config() -> align_config<align_enum::dynamic_config>;

}
