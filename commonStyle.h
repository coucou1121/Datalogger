#ifndef COMMONSTYLE_H
#define COMMONSTYLE_H

#include <QColor>
#include <QPushButton>
#include <QDoubleSpinBox>
#include <QSpinBox>

//main windows
//size
#define MINIMUM_WIDTH_SIZE 1280
#define MINIMUM_HEIGHT_SIZE 720

//color
#define BACKGROUD_COLOR 160,160,160                                 //RGB, R=160, G=160, B=160  aplha = 255
#define BACKGROUD_COLOR_BOTTOM_BAR 125,125,125                      //RGB, R=125, G=125, B=125  alpha = 255
#define BACKGROUD_COLOR_FRAME 119,119,119                           //RGB, R=119, G=119, B=119  alpha = 255
#define BACKGROUD_COLOR_ERROR_FRAME 255,160,160                     //RGB, R=255, G=160, B=160  alpha = 255
#define BACKGROUD_COLOR_BUTTON_STATUS_BAR_SELECTED 77,77,77         //RGB, R=77, G=77, B=77  alpha = 255
#define BACKGROUD_COLOR_BUTTON_STATUS_BAR_UNSELECTED 221,221,221    //RGB, R=221, G=221, B=221  alpha = 255

//ANALOG plot
//size
#define ANALOG_PLOT_MINIMUM_WIDTH_SIZE 960
#define ANALOG_PLOT_MINIMUM_HEIGHT_SIZE 22

//color
#define ANALOG_PLOT_BACKGROUD_COLOR         25,25,25                //RGB, R=25,    G=25,   B=25,   aplha = 255
#define ANALOG_PLOT_BACKGROUD_COLOR_PLOT    25,25,25                //RGB, R=25,    G=25,   B=25,   aplha = 255

#define ANALOG_PLOT_GRID_COLOR              255, 255, 0, 100        //RGB, R=140,   G=140,  B=140   aplha = 100
#define ANALOG_PLOT_AXE_GRID_COLOR          255, 255, 0             //RGB, R=140,   G=140,  B=140   aplha = 255

#define ANALOG_PLOT_AXIS_COLOR              250, 250, 250           //RGB, R=140,   G=140,  B=140   aplha = 255
#define ANALOG_PLOT_AXIS_TICK_COLOR         250, 250, 250           //RGB, R=140,   G=140,  B=140   aplha = 255
#define ANALOG_PLOT_AXIS_SUB_TICK_COLOR     250, 250, 250           //RGB, R=140,   G=140,  B=140   aplha = 255
#define ANALOG_PLOT_AXIS_TICK_LABEL_COLOR   250, 250, 250           //RGB, R=140,   G=140,  B=140   aplha = 255
//pen
#define ANALOG_PLOT_TRACE                   0, 153, 255               //RGB, R=0,   G=153,  B=255   aplha = 255

//DIGITAL plot
//size
#define DIGITAL_PLOT_MINIMUM_WIDTH_SIZE 960
#define DIGITAL_PLOT_MINIMUM_HEIGHT_SIZE 22

//color
#define DIGITAL_PLOT_BACKGROUD_COLOR         25,25,25                //RGB, R=25,    G=25,   B=25,   aplha = 255
#define DIGITAL_PLOT_BACKGROUD_COLOR_PLOT    25,25,25                //RGB, R=25,    G=25,   B=25,   aplha = 255

#define DIGITAL_PLOT_GRID_COLOR              255, 255, 0, 100        //RGB, R=140,   G=140,  B=140   aplha = 100
#define DIGITAL_PLOT_AXE_GRID_COLOR          255, 255, 0             //RGB, R=140,   G=140,  B=140   aplha = 255

#define DIGITAL_PLOT_AXIS_COLOR              250, 250, 250           //RGB, R=140,   G=140,  B=140   aplha = 255
#define DIGITAL_PLOT_AXIS_TICK_COLOR         250, 250, 250           //RGB, R=140,   G=140,  B=140   aplha = 255
#define DIGITAL_PLOT_AXIS_SUB_TICK_COLOR     250, 250, 250           //RGB, R=140,   G=140,  B=140   aplha = 255
#define DIGITAL_PLOT_AXIS_TICK_LABEL_COLOR   250, 250, 250           //RGB, R=140,   G=140,  B=140   aplha = 255
//pen
#define DIGITAL_PLOT_TRACE                   51, 204, 51             //RGB, R=51,   G=204,  B=51   aplha = 255

//error
#define ERROR_LINE_COLOR_IN_TROUBLE           255, 0, 0              //RGB, R=255,   G=0,  B=0   aplha = 255

class CommonStyle
{
public:
    CommonStyle();

    //background
    QColor getBackGroundColor() const;
    QColor getBackGroundColorBottomBar() const;
    QColor getBackGroundColorAnalogPlot() const;
    QColor getBackGroundColorFrame() const;
    QColor getBackGroundColorErrorFrame() const;
    QColor getBackGroundColorButtonStatusbarSelected() const;
    QColor getBackGroundColorButtonStatusbarUnselected() const;

    //plot
    QColor getGridColorAnalogPlot() const;
    QColor getAxisGridColorAnalogPlot() const;
    QColor getAxisColorAnalogPlot() const;
    QColor getAxisTickColorAnalogPlot() const;
    QColor getAxisSubTickColorAnalogPlot() const;
    QColor getAxisTickLabelColorAnalogPlot() const;

    //pen
    //analog trace
    QColor getTraceColorAnalogPlot() const;

    //digital trace
    QColor getTraceColorDigitalPlot() const;

    //error line
    QColor getErrorLineInTrouble() const;

    //pushbutton unselect Shape
    void setPushButtonUnselected(QPushButton *pushButton);
    void setPushButtonBlocked(QPushButton *pushButton);

    //doublspinbox Shape
    void setSpinBoxShape(QSpinBox *spinBox);
    void setDoublespinBoxShape(QDoubleSpinBox *doubleSpinBox);

private:
    //analog plot
    //backrgound
    QColor _backGroundColor;
    QColor _backGroundColorBottomBar;
    QColor _backGroundColorAnalogPlot;
    QColor _backGroundColorFrame;
    QColor _backGroundColorErrorFrame;
    QColor _backGroundColorButtonStatusbarSelected;
    QColor _backGroundColorButtonStatusbarUnselected;

    //Grid
    QColor _gridColorAnalogPlot;
    QColor _axisGridColorAnalogPlot;

    //Axis
    QColor _axisColorAnalogPlot;
    QColor _axisTickColorAnalogPlot;
    QColor _axisSubTickColorAnalogPlot;
    QColor _axisTickLabelColorAnalogPlot;

    //pen
    //analoge trace
    QColor _traceColorAnalogPlot;

    //digital trace
    QColor _traceColorDigitalPlot;

    //error line
    QColor _errorLineInTrouble;
};

#endif // COMMONSTYLE_H
