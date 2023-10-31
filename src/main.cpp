#include <CpuRunner/RunnerWidget.h>

#include <QApplication>
#include <cstdlib>

#include <iostream>

#include "CpuUsage.h"
#include "INI.h"
#include <CpuRunner/OptionsManager.h>

using namespace CpuRunner;

bool isXServerEnvironment();
void initializeOptions();
int initializeApplication(int argc, char** argv);

int main(int argc, char** argv) {
    std::cout << "Hello, I'm CpuRunner!" << std::endl;
    initializeOptions();
    return initializeApplication(argc, argv);
}

bool isXServerEnvironment() {
    return std::getenv("DISPLAY") != nullptr;
}

void initializeOptions() {
    INI::Loader loader("options.ini");
    OptionsManager *manager = OptionsManager::GetInstance(loader);
    // TODO: load something..
}

int initializeApplication(int argc, char** argv) {
    QApplication app(argc, argv);
    
    CpuRunner::RunnerWidget window;
    window.resize(400, 300);

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
