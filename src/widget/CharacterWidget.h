#ifndef CHARACTER_WINDOW_H
#define CHARACTER_WINDOW_H

#define COOL "../assets/normal.png"
#define NORMAL "../assets/cool.png"

#include <string>

#include <QWidget>
#include <QLabel>
#include <QPixmap>
#include <QPoint>
#include <QTimer>
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

public slots:
    void updateCpuUsage();

private:
    QLabel *label;
    QPoint offset;
    QTimer *guiTimer;
    std::string previous;

    void updateImage(QPixmap pixmap);
    bool checkIsSameAsPrevious(std::string newString);
};

#endif
