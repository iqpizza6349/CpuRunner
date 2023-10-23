#ifndef CHARACTER_WINDOW_H
#define CHARACTER_WINDOW_H

#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QString>
#include <QPixmap>
#include <QBitmap>
#include <QPoint>
#include <QImage>
#include <QPainter>

#include <QMouseEvent>

#include <QDebug>

class CharacterWidget : public QWidget {
    Q_OBJECT

public:
    CharacterWidget();
    ~CharacterWidget();

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

private:
    QLabel *label;
    QPoint offset;
};

#endif
