#pragma once
#include <CpuRunner/Widget.h>
#include <CpuRunner/UsageLabel.h>
#include <CpuRunner.h>

#include <QPixmap>
#include <QPoint>
#include <QTimer>
#include <QMouseEvent>

#include <string>

namespace CpuRunner {
    class UsageLabel;

    class RunnerWidget : public QWidget {
    public:
        RunnerWidget();
        
    protected:
        void mousePressEvent(QMouseEvent *event) override {
            offset = event->pos();
        }

        void mouseMoveEvent(QMouseEvent *event) override {
            if (event->buttons() && Qt::LeftButton) {
                QPoint newPos = event->globalPos() - offset;
                move(newPos);
            }
        }

    public slots:
        void update();

    private:
        QLabel *label;
        QPoint offset;
        QTimer *guiTimer;
        std::string previous;
        UsageLabel *usageLabel;

        int prevIdleTime;
        int prevTotalTime;

        void updateGUI(QPixmap pixmap);
        bool checkIsSameAsPrevious(std::string newString) {
            return previous == newString;
        }
    };
}
