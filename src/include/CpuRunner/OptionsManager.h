#pragma once
#include <INI/Loader.h>

#include <CpuRunner/CpuRunnerOption.h>
#include <variant>

namespace CpuRunner {
    class OptionsManager {
        public:
            /** OptionsManager class should not be cloneable */
            OptionsManager(OptionsManager &other) = delete;

            /** OptionsManager should not be assignable */
            void operator=(const OptionsManager &) = delete;

            static OptionsManager *GetInstance(const INI::Loader &loader = nullLoader);

            std::variant<std::string, int> getOptionValue(CpuRunnerOption::Option option, bool isNumber = false);

            int convertToInt(const std::variant<std::string, int> &value) {
                if (std::holds_alternative<int>(value)) {
                    int intValue = std::get<int>(value);
                    return intValue;
                }
                return 0;
            }

            std::string convertToString(const std::variant<std::string, int> &value) {
                if (std::holds_alternative<std::string>(value)) {
                    std::string stringValue = std::get<std::string>(value);
                    return stringValue;
                }
                return nullptr;
            }
            
        protected:
            OptionsManager(const INI::Loader loader): loader_(loader) {
                // do nothing
            }

            static OptionsManager *manager_;

            INI::Loader loader_;
        private:
            static const INI::Loader nullLoader;
    };
}
