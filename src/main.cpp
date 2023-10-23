#include <QApplication>
#include <cstdlib>

#include <iostream>

#include "widget/CharacterWidget.h"
#include "CpuUsage.h"

using CpuUsage::usage;

bool isXServerEnvironment();

int main(int argc, char** argv) {
    std::cout << "Hello, I'm CpuRunner!\n" << std::endl;
    std::cout << "CPU Usage: " << usage() << "%" << std::endl;

    QApplication app(argc, argv);
    
    CharacterWidget window;
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
