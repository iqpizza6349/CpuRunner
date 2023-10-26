#include <CpuRunner/RunnerWidget.h>

#include <QApplication>
#include <cstdlib>

#include <iostream>

#include "CpuUsage.h"

bool isXServerEnvironment();

int main(int argc, char** argv) {
    std::cout << "Hello, I'm CpuRunner!" << std::endl;
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

bool isXServerEnvironment() {
    return std::getenv("DISPLAY") != nullptr;
}
