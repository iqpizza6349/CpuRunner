#include "CharacterWidget.h"
#include <iostream>

#include <CpuUsage.h>

CharacterWidget::CharacterWidget(): QWidget() {
    label = new QLabel(this);

    QPixmap pixmap(NORMAL);
    updateImage(pixmap);

    guiTimer = new QTimer(this);
    connect(guiTimer, &QTimer::timeout, this, &CharacterWidget::updateCpuUsage);
    guiTimer->start(1000);
}

CharacterWidget::~CharacterWidget() {
}

bool CharacterWidget::checkIsSameAsPrevious(std::string newString) {
    return (previous == newString);
}

void CharacterWidget::updateCpuUsage() {
    double usage = CpuUsage::usage();
    std::string filename = (usage > 33.0) ? NORMAL : COOL;
    if (!checkIsSameAsPrevious(filename)) {
        previous = filename;
        QString filepath = QString::fromStdString(filename);
        QPixmap pixmap(filepath);
        updateImage(pixmap);
    }
}

void CharacterWidget::updateImage(QPixmap pixmap) {
    if (pixmap.isNull()) {
        qDebug() << "Failed to load image!";
    } else {
        this->setAutoFillBackground(true);
        this->setMask(pixmap.mask());
        label->setPixmap(pixmap);
        label->adjustSize();
    }
}
