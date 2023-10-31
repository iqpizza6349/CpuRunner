#include <CpuRunner/OptionsManager.h>

namespace CpuRunner {
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
