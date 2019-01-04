#ifndef ERASER_H
#define ERASER_H
#include "shap.h"


class Eraser : public Shap
{
    //Q_OBJECT
public:
    Eraser();

    void paint(QPainter& painter);
    void paint_eraser(QPainter &painter, QPixmap& pix);

protected:
    bool isfinish;
    QPixmap ppix;
};

#endif // ERASER_H
