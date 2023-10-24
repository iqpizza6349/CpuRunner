#pragma once
#include <QObject>
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>

#include <QString>

namespace CpuRunner {
    class UsageLabel : public QObject {

    public:
        UsageLabel(QWidget *parent = nullptr);

        virtual void updateUsage(unsigned int usage = 0);
    
    private:
        QVBoxLayout *layout;
        QLabel *label;
    };
}
