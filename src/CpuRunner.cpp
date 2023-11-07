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

    std::string getImageType(ImageType imageType) {
        switch (imageType) {
            case COOL:
                return "cool";
                break;
            case NORMAL:
                return "normal";
                break;
            case HOT:
                return "hot";
                break;
            case EXTREME:
                return "extreme";
                break;
            case MELT:
                return "melt";
                break;
            default:
                return "null";
                break;
        }
    }

    std::string getImage(ImageType imageType) {
        auto images = manager->getOptionValue(CpuRunnerOption::Option::WIDGET_IMAGES);
        std::string directory = manager->convertToString(images);
        std::string type = getImageType(imageType);
        return directory.append("/")
                        .append(type)
                        .append(".png");
    }
}
