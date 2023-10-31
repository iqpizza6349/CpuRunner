#include <CpuRunner/RunnerWidget.h>
#include <iostream>

#include <QImage>
#include <QBitmap>
#include <QString>
#include <QDebug>

#include <CpuUsage.h>

namespace CpuRunner {
    RunnerWidget::RunnerWidget(): QWidget() {
        this->setAutoFillBackground(true);
        label = new QLabel(this);
        usageLabel = new UsageLabel(this);
        
        QPixmap pixmap(NORMAL);
        updateGUI(pixmap);
        
        guiTimer = new QTimer(this);
        connect(guiTimer, &QTimer::timeout, this, &RunnerWidget::update);
        guiTimer->start(1000);
    }
    
    void RunnerWidget::update() {
        int usage = Cpusage::usage();
        usageLabel->updateUsage(usage);
        std::string filename = (usage > 33) ? NORMAL : COOL;
        if (!checkIsSameAsPrevious(filename)) {
            previous = filename;
            QString filepath = QString::fromStdString(filename);
            QPixmap pixmap(filepath);
            updateGUI(pixmap);
        }
    }

    void RunnerWidget::updateGUI(QPixmap pixmap) {
        if (pixmap.isNull()) {
            qDebug() << "Failed to load image!";
        } else {
            this->setMask(pixmap.mask());
            label->setPixmap(pixmap);
            label->adjustSize();
        }
    }
}
