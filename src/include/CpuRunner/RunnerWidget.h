#pragma once
#pragma warning(disable: 4996)
#include <CpuRunner/UsageLabel.h>
#include <CpuRunner.h>

#include <QPixmap>
#include <QPoint>
#include <QTimer>
#include <QMouseEvent>
#include <QCoreApplication>

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

        void closeEvent(QCloseEvent *event) override {
            QCoreApplication::quit();
            QWidget::closeEvent(event);
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

        std::string changeImage(int usage) {
            if (usage >= 83) {
                return getImage(CpuRunner::MELT);
            } else if (usage >= 67) {
                return getImage(CpuRunner::EXTREME);
            } else if (usage >= 45) {
                return getImage(CpuRunner::HOT);
            } else if (usage >= 16) {
                return getImage(CpuRunner::NORMAL);
            } else {
                return getImage(CpuRunner::COOL);
            }
        }
    };
}
