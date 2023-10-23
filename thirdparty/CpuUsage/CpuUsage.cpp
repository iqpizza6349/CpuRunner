#include "CpuUsage.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unistd.h>

namespace CpuUsage {
    double usage() {
        std::ifstream statFile("/proc/stat");
        std::string line;
        std::getline(statFile, line);
        statFile.close();

        std::istringstream stream(line);
        std::string cpuLabel;
        unsigned long user, nice, system, idle, iowait, irq, softirq, steal, guest, guest_nice;

        stream >> cpuLabel >> user >> nice >> system >> idle >> iowait >> irq >> softirq >> steal >> guest >> guest_nice;

        // CPU usage at first point
        unsigned long startIdle = idle + iowait;
        unsigned long startNonIdle = user + nice + system + irq + softirq + steal + guest + guest_nice;
        unsigned long startTime = startIdle + startNonIdle;

        sleep(1); // 1 ms wait .

        statFile.open("/proc/stat");
        std::getline(statFile, line);
        statFile.close();

        std::istringstream stream2(line);
        stream2 >> cpuLabel >> user >> nice >> system >> idle >> iowait >> irq >> softirq >> steal >> guest >> guest_nice;

        // CPU usage at second point
        unsigned long endIdle = idle + iowait;
        unsigned long endNonIdle = user + nice + system + irq + softirq + steal + guest + guest_nice;
        unsigned long endTime = endIdle + endNonIdle;

        unsigned long totalTime = endTime - startTime;
        unsigned long totalIdle = endIdle - startIdle;

        return ((totalTime - totalIdle) / static_cast<double>(totalTime)) * 100.0;
    }
}
