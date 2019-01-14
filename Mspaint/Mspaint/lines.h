#ifndef LINES_H
#define LINES_H
#include "shap.h"
#include <QPainter>


class Lines : public QObject,public Shap{

    Q_OBJECT
public:

    Lines();

    void paint(QPainter& painter);
    void paint_Lines(QPainter &painter, QPixmap& pix);

protected:
//    QPixmap pix;
    bool isfinish;


};

#endif // LINES_H
