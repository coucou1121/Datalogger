#ifndef BASEWINDOW_H
#define BASEWINDOW_H

#include <QWidget>

namespace Ui {
class BaseWindow;
}

class BaseWindow : public QWidget
{
    Q_OBJECT

public:
    explicit BaseWindow(QWidget *parent = 0);
    ~BaseWindow();

    void setTitle(const QString &title);
    void setVersion(const QString &version);

private:
    Ui::BaseWindow *ui;

    //title
    QString _title;

    //Version
    QString _version;
};

#endif // BASEWINDOW_H
