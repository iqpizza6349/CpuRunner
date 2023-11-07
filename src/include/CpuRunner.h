#pragma once
#ifndef __CPU_RUNNER_H__
#define __CPU_RUNNER_H__

#include <CpuRunner/OptionsManager.h>
#include <string>

#include <QDebug>

namespace CpuRunner {
    static OptionsManager *manager;
    static int debug;

    bool isDebug();

    void initialize();

    enum ImageType {
        COOL,
        NORMAL,
        HOT,
        EXTREME,
        MELT
    };

    std::string getImageType(ImageType imageType);

    std::string getImage(ImageType imageType);
}

#endif
