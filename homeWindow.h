#ifndef HomeWindow_H
#define HomeWindow_H

#include <QWidget>

namespace Ui {
class HomeWindow;
}

class HomeWindow : public QWidget
{
    Q_OBJECT

public:
    explicit HomeWindow(QWidget *parent = 0);
    ~HomeWindow();

    void setTitle(const QString &title);
    void setVersion(const QString &version);

private:
    Ui::HomeWindow *ui;

    //title
    QString _title;

    //Version
    QString _version;
};

#endif // HomeWindow_H
