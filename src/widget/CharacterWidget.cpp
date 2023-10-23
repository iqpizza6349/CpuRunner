#include "CharacterWidget.h"

CharacterWidget::CharacterWidget(): QWidget() {
    label = new QLabel(this);
    QPixmap pixmap("../assets/normal.png");
    if (pixmap.isNull()) {
        qDebug() << "Failed to load image!";
    } else {
        this->setAutoFillBackground(true);
        this->setMask(pixmap.mask());
        label->setPixmap(pixmap);
    }
}

CharacterWidget::~CharacterWidget() {
    // destructor
}
