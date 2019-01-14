#ifndef LINE_H
#define LINE_H
#include "shap.h"
class Line:public Shap
{
public:
    Line();

    void paint(QPainter &painter);

  //  void newpaint(QPainter &painter,QPixmap &pix);
};

#endif // LINE_H
