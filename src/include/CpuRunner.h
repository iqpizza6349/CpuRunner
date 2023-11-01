#pragma once
#ifndef __CPU_RUNNER_H__
#define __CPU_RUNNER_H__

#include <CpuRunner/OptionsManager.h>

#include <QDebug>

namespace CpuRunner {
    static OptionsManager *manager;

    bool isDebug();

    void initialize();
}

#endif
