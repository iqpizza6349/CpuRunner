#include <CpuRunner/UsageLabel.h>

#include <string>

namespace CpuRunner {
    UsageLabel::UsageLabel(QWidget *parent): QObject(parent) {
        layout = new QVBoxLayout(parent);
        label = new QLabel("0%", parent);
        layout->addWidget(label);
        layout->setAlignment(Qt::AlignBottom | Qt::AlignRight);
    }
    
    void UsageLabel::updateUsage(unsigned int usage) {
        std::string text = std::to_string(usage) + "%";
        label->setText(QString::fromStdString(text));
    }
}
