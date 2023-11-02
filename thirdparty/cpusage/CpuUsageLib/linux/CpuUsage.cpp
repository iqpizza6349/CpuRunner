#include <CpuUsage.h>

#include <QFile>

namespace Cpusage {
    int usage(int *previousIdleTime, int *previousTotalTime) {
        QFile file("/proc/stat");
        file.open(QFile::ReadOnly);
        const QList<QByteArray> times = file.readLine().simplified().split(' ').mid(1);
        const int idleTime = times.at(3).toInt();
        int totalTime = 0;
        foreach (const QByteArray &time, times) {
            totalTime += time.toInt();
        }
        int percent = (1 - (1.0*idleTime-*previousIdleTime) / (totalTime-*previousTotalTime)) * 100.0;
        *previousIdleTime = idleTime;
        *previousTotalTime = totalTime;
        return percent;
    }
}
