#ifndef CPU_USAGE_H
#define CPU_USAGE_H
#define DEFAULT_CPU_USAGE -1.0

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unistd.h>

namespace CpuUsage {
    double usage();
}

#endif
