#include <CpuRunner/OptionsManager.h>

namespace CpuRunner {

    const std::unordered_map<CpuRunnerOption::Option, std::string> 
            CpuRunnerOption::enumToString = {
        { Option::DEBUG_DEBUG, "debug.debug" },
        { Option::DEBUG_LOGGING, "debug.logging" },
        { Option::WIDGET_IMAGES, "widget.images" },
        { Option::WIDGET_WIDTH, "widget.widget_width" },
        { Option::WIDGET_HEIGHT, "widget.widget_height" },
        { Option::WIDGET_TOP, "widget.keep_top" },
        { Option::WIDGET_SLEEP, "widget.could_sleep" }
    };

    OptionsManager *OptionsManager::manager_ = nullptr;

    OptionsManager *OptionsManager::GetInstance(const INI::Loader &loader) {
        // if loader is null, check if the single instance has already created.
        if (loader.isNull()) {
            // but when single instance has not created?
            if (manager_ == nullptr) {
                throw (loader);
            }
        }

        if (manager_ == nullptr) {
            manager_ = new OptionsManager(loader);
        }
        return manager_;
    }
}
