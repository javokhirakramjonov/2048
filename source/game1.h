#ifndef GAME1_H
#define GAME1_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class GAME1; }
QT_END_NAMESPACE

class GAME1 : public QMainWindow
{
    Q_OBJECT

public:
    GAME1(QWidget *parent = nullptr);
    ~GAME1();

private:
    Ui::GAME1 *ui;
private:
    void keyPressEvent(QKeyEvent *event);
    void goup();
    void goright();
    void godown();
    void goleft();
    void gorandom();
    void docopy();
    void check();
    void setcolor();
};
#endif // GAME1_H
