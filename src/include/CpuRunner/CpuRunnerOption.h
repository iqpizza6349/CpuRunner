#pragma once

#include <string>
#include <unordered_map>

namespace CpuRunner {
    struct CpuRunnerOption {
        enum class Option {
            DEBUG_DEBUG,
            DEBUG_LOGGING,
            WIDGET_IMAGES,
            WIDGET_WIDTH,
            WIDGET_HEIGHT,
            WIDGET_TOP,
            WIDGET_SLEEP
        };

        /// @brief Implements in OptionsManager.cpp
        static const std::unordered_map<Option, std::string> enumToString;

        static std::string toString(Option option) {
            auto it = enumToString.find(option);
            return (it != enumToString.end()) ? it->second : "Unknown";
        }
    };
}
