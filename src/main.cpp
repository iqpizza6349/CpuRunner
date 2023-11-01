#include <CpuRunner/RunnerWidget.h>

#include <QApplication>
#include <cstdlib>

#include <iostream>

#include "CpuUsage.h"
#include "INI.h"
#include "CpuRunner.h"

using namespace CpuRunner;

OptionsManager *options;
bool isXServerEnvironment();
void initializeOptions();
int initializeApplication(int argc, char** argv);

int main(int argc, char** argv) {
    std::cout << "Hello, I'm CpuRunner!" << std::endl;
    initializeOptions();
    initialize();
    return initializeApplication(argc, argv);
}

bool isXServerEnvironment() {
    return std::getenv("DISPLAY") != nullptr;
}

void initializeOptions() {
    INI::Loader loader("options.ini");
    options = OptionsManager::GetInstance(loader);
}

int initializeApplication(int argc, char** argv) {
    QApplication app(argc, argv);
    
    CpuRunner::RunnerWidget window;
    int width = options->convertToInt(options->getOptionValue(CpuRunnerOption::Option::WIDGET_WIDTH, true));
    int height = options->convertToInt(options->getOptionValue(CpuRunnerOption::Option::WIDGET_HEIGHT, true));
    window.resize(width, height);

    Qt::WindowType type = Qt::FramelessWindowHint;
    if (isXServerEnvironment()) {
        type = Qt::X11BypassWindowManagerHint;
    }

    window.setWindowFlags(type);
    window.setWindowTitle("Character Display");
    window.setAttribute(Qt::WA_TranslucentBackground);

    window.show();
    return app.exec();
}
