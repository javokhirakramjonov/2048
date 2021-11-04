#include "game1.h"
#include "ui_game1.h"
#include <QKeyEvent>
#include <qvector.h>
#include <bits/stdc++.h>

QString value;
int num;
QLabel *a[6][6];
QString copy[6][6];
QString colors[15];

GAME1::GAME1(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GAME1)
{
    ui->setupUi(this);
    colors[0] = "#C7C7C7";
    colors[1] = "#DFDFDF";
    colors[2] = "#294763";
    colors[3] = "#641785";
    colors[4] = "#A61C03";
    colors[5] = "#FF6800";
    colors[6] = "#FF2A00";
    colors[7] = "#FFE400";
    colors[8] = "#BDFF00";
    colors[9] = "#3EFF00";
    colors[10]= "#00FF97";
    colors[11]= "#0087FF";
    colors[12]= "#5E81D1";
    colors[13]= "#E19B20";
    colors[14]= "#227F96";
    for(int i = 1; i < 5; ++ i)
        {
            for(int j = 1; j < 5; ++ j)
            {
                a[i][j] = GAME1::findChild<QLabel *>("c" + QString::number(i) + QString::number(j));
            }
        }
    gorandom();
    gorandom();
    setcolor();
}

GAME1::~GAME1()
{
    delete ui;
}

void GAME1::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Up)
        GAME1::goup();
    else if(event->key() == Qt::Key_Right)
        GAME1::goright();
    else if(event->key() == Qt::Key_Down)
        GAME1::godown();
    else if(event->key() == Qt::Key_Left)
        GAME1::goleft();
}
void GAME1::goup()
{
    docopy();
    for(int i = 1; i < 5; ++ i)
    {
        QVector<int> b;
        for(int j = 1; j < 5; ++ j)
            if(a[j][i]->text() != "")
                   b.push_back(a[j][i]->text().toInt());
        for(int j = 1; j < (int)b.size(); ++ j)
        {
            if(b[j] == b[j - 1])
            {
                b[j - 1] <<= 1;
                b[j] = 0;
            }
        }
        for(int j = 1; j < 5; ++ j)
        {
            while(!b.empty() && b[0] == 0)
                b.erase(b.begin());
            if(!b.empty())
            {
                a[j][i]->setText(QString::number(b[0]));
                b.erase(b.begin());
            }
            else
            {
                while(j < 5)
                {
                    a[j][i]->setText("");
                    ++j;
                }
            }
        }
    }
    check();
    setcolor();
}

void GAME1::goright()
{
    docopy();
    for(int i = 1; i < 5; ++ i)
    {
        QVector<int> b;
        for(int j = 4; j > 0; -- j)
            if(a[i][j]->text() != "")
                   b.push_back(a[i][j]->text().toInt());
        for(int j = 1; j < b.size(); ++ j)
        {
            if(b[j] == b[j - 1])
            {
                b[j - 1] <<= 1;
                b[j] = 0;
            }
        }
        for(int j = 4; j > 0; -- j)
        {
            while(!b.empty() && b[0] == 0)
                b.erase(b.begin());
            if(!b.empty())
            {
                a[i][j]->setText(QString::number(b[0]));
                b.erase(b.begin());
            }
            else
            {
                while(j > 0)
                {
                    a[i][j]->setText("");
                    --j;
                }
            }
        }
    }
    check();
    setcolor();
}

void GAME1::godown(){
    docopy();
    for(int i = 1; i < 5; ++ i)
    {
        QVector<int> b;
        for(int j = 4; j > 0; -- j)
            if(a[j][i]->text() != "")
                   b.push_back(a[j][i]->text().toInt());
        for(int j = 1; j < b.size(); ++ j)
        {
            if(b[j] == b[j - 1])
            {
                b[j - 1] <<= 1;
                b[j] = 0;
            }
        }
        for(int j = 4; j > 0; -- j)
        {
            while(!b.empty() && b[0] == 0)
                b.erase(b.begin());
            if(!b.empty())
            {
                a[j][i]->setText(QString::number(b[0]));
                b.erase(b.begin());
            }
            else
            {
                while(j > 0)
                {
                    a[j][i]->setText("");
                    --j;
                }
            }
        }
    }
    check();
    setcolor();
}

void GAME1::goleft()
{
    docopy();
    for(int i = 1; i < 5; ++ i)
    {
        QVector<int> b;
        for(int j = 1; j < 5; ++ j)
            if(a[i][j]->text() != "")
                   b.push_back(a[i][j]->text().toInt());
        for(int j = 1; j < (int)b.size(); ++ j)
        {
            if(b[j] == b[j - 1])
            {
                b[j - 1] <<= 1;
                b[j] = 0;
            }
        }
        for(int j = 1; j < 5; ++ j)
        {
            while(!b.empty() && b[0] == 0)
                b.erase(b.begin());
            if(!b.empty())
            {
                a[i][j]->setText(QString::number(b[0]));
                b.erase(b.begin());
            }
            else
            {
                while(j < 5)
                {
                    a[i][j]->setText("");
                    ++j;
                }
            }
        }
    }
    check();
    setcolor();
}

void GAME1::gorandom()
{
    int mx = 2;
    for(int i = 1; i < 5; ++ i)
        for(int j = 1; j < 5; ++ j)
            if(a[i][j]->text() != "")
                mx = qMax(mx, a[i][j]->text().toInt());
    int mp = log2(mx);
    srand(time(0));
    mp = rand() % mp;
    ++ mp;
    mp = qMax(1, mp - 2);
    QVector<QPair<int, int> > emce;
    for(int i = 1; i < 5; ++ i)
        for(int j = 1; j < 5; ++ j)
            if(a[i][j]->text() == "")
                emce.push_back(qMakePair(i, j));
    if(emce.empty())
        return;
    QPair<int, int> x = emce[rand() % (int)emce.size()];
    a[x.first][x.second]->setText(QString::number(1 << mp));
}

void GAME1::docopy()
{
    for(int i = 1; i < 5; ++ i)
        for(int j = 1; j < 5; ++ j)
            copy[i][j] = a[i][j]->text();
}

void GAME1::check()
{
    for(int i = 1; i < 5; ++ i)
    {
        for(int j = 1; j < 5; ++ j)
        {
            if(QString::compare(copy[i][j], a[i][j]->text()) != 0)
            {
                gorandom();
                j = 5;
                i = 5;
            }
        }
    }
}

void GAME1::setcolor()
{
    int dc = 0;
    QString changes;
    for(int i = 1; i < 5; ++ i)
    {
        for(int j = 1; j < 5; ++ j)
        {
            dc = 0;
            if(a[i][j]->text().size() != 0)
                dc = log2(a[i][j]->text().toInt());
            if(dc <= 1)
                changes = "QLabel{background-color:" + colors[dc] + ";color:#9C9C9C;}";
            else
                changes = "QLabel{background-color:" + colors[dc] + ";color:#F2F2F2;}";
            a[i][j]->setStyleSheet(changes);
        }
    }
}

