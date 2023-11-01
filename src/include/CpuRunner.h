#pragma once
#ifndef __CPU_RUNNER_H__
#define __CPU_RUNNER_H__

#include <CpuRunner/RunnerWidget.h>
#include <CpuRunner/UsageLabel.h>
#include <CpuRunner/Widget.h>
#include <CpuRunner/OptionsManager.h>

#include <QDebug>

namespace CpuRunner {
    const INI::Loader OptionsManager::nullLoader;

    bool isDebug() {
        OptionsManager *manager = OptionsManager::GetInstance();
        std::variant<std::string, int> value = manager->getOptionValue(CpuRunnerOption::Option::DEBUG_DEBUG);
        std::string str = manager->convertToString(value);
        std::transform(str.begin(), str.end(), str.begin(), ::tolower);
        std::istringstream is(str);
        bool b;
        is >> std::boolalpha >> b;
        return b;
    }
}

#endif
