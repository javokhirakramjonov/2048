#include "Game2048.h"
#include "ui_game2048.h"
#include <QKeyEvent>
#include <qvector.h>
#include <bits/stdc++.h>

QString value;
int num;
QLabel *a[6][6];
QString copy[6][6];

Game2048::Game2048(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Game2048)
{
    ui->setupUi(this);
    ui->c32->setText("2");
    ui->c42->setText("2");
    for(int i = 1; i < 5; ++ i)
    {
        for(int j = 1; j < 5; ++ j)
        {
            a[i][j] = Game2048::findChild<QLabel *>("c" + QString::number(i) + QString::number(j));
        }
    }
}

Game2048::~Game2048()
{
    delete ui;
}

void Game2048::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Up)
        Game2048::goup();
    else if(event->key() == Qt::Key_Right)
        Game2048::goright();
    else if(event->key() == Qt::Key_Down)
        Game2048::godown();
    else if(event->key() == Qt::Key_Left)
        Game2048::goleft();
}
void Game2048::goup()
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
}

void Game2048::goright()
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
}

void Game2048::godown(){
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
}

void Game2048::goleft()
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
}

void Game2048::gorandom()
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

void Game2048::docopy()
{
    for(int i = 1; i < 5; ++ i)
        for(int j = 1; j < 5; ++ j)
            copy[i][j] = a[i][j]->text();
}

void Game2048::check()
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
