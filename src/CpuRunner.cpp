#include <CpuRunner.h>

#include <iostream>

namespace CpuRunner {

    bool isDebug() {
        if (debug == -1) {
            if (!manager) {
                return false;
            }
        
            std::variant<std::string, int> value = manager->getOptionValue(CpuRunnerOption::Option::DEBUG_DEBUG);
            std::string str = manager->convertToString(value);
            return (str == "ON");
        } else {
            return debug;
        }
    }

    void initialize() {
        debug = -1;
        manager = OptionsManager::GetInstance();
        if (isDebug()) {
            debug = 1;
            qDebug() << "CpuRunner is on the debug";
        } else {
            debug = 0;
            qDebug() << "CpuRunner is not on the debug";
        }
    }
}
