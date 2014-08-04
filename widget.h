#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSystemTrayIcon>
#include <QMessageBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QLineEdit>
#include <qlabel>
#include <QSpinBox>


class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
private slots:
    void showMsg();
    void showClickMsg();

private:
    QSpinBox *comboTime;
    QLineEdit *editMsg;
    QLineEdit *editClickMsg;
    QPushButton *btnShow;

    QSystemTrayIcon *trayIcon;
};

#endif // WIDGET_H
