#include "CpuUsage.h"

namespace CpuUsage {
    double usage() {
        std::ifstream statFile("/proc/stat");
        std::string line;

        if (statFile.is_open()) {
            std::getline(statFile, line);
            if (line.substr(0, 3) == "cpu") {
                std::istringstream iss(line);
                std::string cpuLabel;
                unsigned long user, nice, system, idle, iowait, irq, softirq, steal, guest, guest_nice;
                iss >> cpuLabel >> user >> nice >> system >> idle >> iowait >> irq >> softirq >> steal >> guest >> guest_nice;

                // Calculate total CPU usage
                unsigned long totalCpuTime = user + nice + system + idle + iowait + irq + softirq + steal;
                unsigned long idleTime = idle + iowait;
                return 100.0 * (1.0 - (static_cast<double>(idleTime) / totalCpuTime));
            } else {
                std::cerr << "Error: Unexpected format in /proc/stat." << std::endl;
                return DEFAULT_CPU_USAGE;
            }

            statFile.close();
        } else {
            std::cerr << "Error opening /proc/stat file." << std::endl;
            return DEFAULT_CPU_USAGE;
        }
        return DEFAULT_CPU_USAGE;
    }
}
