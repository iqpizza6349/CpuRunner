#include <INI/Loader.h>

#include <CpuRunner/CpuRunnerOption.h>

namespace CpuRunner {
    class OptionsManager {
        public:
            /** OptionsManager class should not be cloneable */
            OptionsManager(OptionsManager &other) = delete;

            /** OptionsManager should not be assignable */
            void operator=(const OptionsManager &) = delete;

            static OptionsManager *GetInstance(const INI::Loader &loader = nullLoader);

            std::string getOption(CpuRunnerOption::Option option) {
                return loader_.getValue(CpuRunnerOption::toString(option));
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
