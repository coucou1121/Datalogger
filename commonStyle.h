#ifndef COMMONSTYLE_H
#define COMMONSTYLE_H

#include <QColor>

#define BACKGROUD_COLOR 82,82,82    //in RGB, R=82, G=82, B=82

class CommonStyle
{
public:
    CommonStyle();


    QColor getBackGroundColor() const;
    void setBackGroundColor(const QColor &value);

private:
    QColor backGroundColor;

};



#endif // COMMONSTYLE_H
