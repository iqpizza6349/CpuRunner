#include <CpuUsage.h>

#include <Windows.h>

namespace Cpusage {
    int usage(int *previousIdleTime, int *previousTotalTime) {
        FILETIME idleTime, kernelTime, userTime;

        if (GetSystemTimes(&idleTime, &kernelTime, &userTime)) {
            int idle = idleTime.dwHighDateTime + idleTime.dwLowDateTime;
            int kernel = kernelTime.dwHighDateTime + kernelTime.dwLowDateTime;
            int user = userTime.dwHighDateTime + userTime.dwLowDateTime;

            int totalTime = kernel + user;
            int idleDelta = idle - *previousIdleTime;
            int totalDelta = totalTime - *previousTotalTime;

            int percent = static_cast<int>((1.0 - 1.0 * idleDelta / totalDelta) * 100.0);
            *previousIdleTime = idle;
            *previousTotalTime = totalTime;
            return percent;
        } else {
            return DEFAULT_CPU_USAGE;
        }
    }
}
