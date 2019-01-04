#ifndef RECT_H
#define RECT_H

#include "shap.h"

class Rect:public Shap
{
public:
    Rect();

    void paint(QPainter &painter);
};

#endif // RECT_H
