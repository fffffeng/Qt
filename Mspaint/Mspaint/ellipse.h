#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "shap.h"

class Ellipse:public Shap
{
public:
    Ellipse();

    void paint(QPainter &painter);
};

#endif // ELLIPSE_H
