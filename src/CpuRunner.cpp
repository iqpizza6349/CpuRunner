#include <CpuRunner.h>

namespace CpuRunner {

    bool isDebug() {
        if (!manager) {
            return false;
        }
        
        std::variant<std::string, int> value = manager->getOptionValue(CpuRunnerOption::Option::DEBUG_DEBUG);
        std::string str = manager->convertToString(value);
        std::transform(str.begin(), str.end(), str.begin(), ::tolower);
        std::istringstream is(str);
        bool b;
        is >> std::boolalpha >> b;
        return b;
    }

    void initialize() {
        manager = OptionsManager::GetInstance();
        if (isDebug()) {
            qDebug() << "CpuRunner is on the debug";
        } else {
            qDebug() << "CpuRunner is not on the debug";
        }
    }
}
