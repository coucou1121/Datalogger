#include "commonStyle.h"

CommonStyle::CommonStyle()
{
    backGroundColor.setRgb(BACKGROUD_COLOR);
}

QColor CommonStyle::getBackGroundColor() const
{
    return backGroundColor;
}

void CommonStyle::setBackGroundColor(const QColor &value)
{
    backGroundColor = value;
}
