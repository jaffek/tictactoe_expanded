#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::czygra(int k)
{
    gra=k;
    pom7=0;
}

void MainWindow::rozmiar(int &N)
{
    N = ui->rozwijana->currentIndex()+3;
    N_= N;
    A_=new char *[N_];
    for(int i=0;i<N_;i++)
    A_[i]=new char [N_];
    boardnull(A_,N_);
}
void MainWindow::newPos()
{
    undo_=new Pos[N_*N_];
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    QPen pen(Qt::blue);
    QPen pen2(Qt::red);
    QPen pen3(Qt::black);
    pen.setWidth(3);
    pen2.setWidth(3);
    pen3.setWidth(3);
    p.setPen(Qt::NoPen);
    p.setBrush(Qt::white);
    p.drawRect(0, 0, 1920, 1080);
    p.setPen(pen);
    for(int i=1;i<N_;i++)
    {

        p.drawLine(100+i*29,90,100+i*29,90+N_*29);
        p.drawLine(100,90+i*29,100+N_*29,90+i*29);
    }
    p.setPen(pen2);
    for(int i=0;i<N_;i++)
      for(int j=0;j<N_;j++)
      {p.setPen(pen2);
      if(A_[i][j]=='O')
       p.drawEllipse(100+j*29,90+i*29,29,29);
      if(A_[i][j]=='X')
        {p.setPen(pen3);
         p.drawLine(100+j*29,90+i*29,130+j*29,120+i*29);
         p.drawLine(100+j*29,120+i*29,130+j*29,90+i*29);
        }
      }
}

void MainWindow::on_pbGraAI_clicked()
{
    gra=1;
    delete [] undo_;
    N_ = ui->rozwijana->currentIndex()+3;
    A_=new char *[N_];
    for(int i=0;i<N_;i++)
    A_[i]=new char [N_];
    boardnull(A_,N_);
    undo_=new Pos[N_*N_];
    pom7=0;
    update();
}


void MainWindow::on_pbGraPvP_clicked()
{
    gra=2;
    delete [] undo_;
    N_ = ui->rozwijana->currentIndex()+3;
    A_=new char *[N_];
    for(int i=0;i<N_;i++)
    A_[i]=new char [N_];
    boardnull(A_,N_);
    undo_=new Pos[N_*N_];
    pom7=0;
    update();
}
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    int pom=gamewin(N_);

    switch(gra)
    {
    case 0:
        break;
    case 1:
    x_m=(int)(event->x()-100)/29;
    y_m=(int)(event->y()-90)/29;
    if(x_m>=0 && x_m<N_ && y_m>=0 && y_m<N_ && event->x()-100>=0 && event->y()-90>=0)
        if(A_[y_m][x_m]==' ')
    {
        A_[y_m][x_m]='X';
        pom7++;
        undo_[pom7-1].x=x_m;
        undo_[pom7-1].y=y_m;
        if(gamecheck(A_,pom,'X',N_)==1)
        {
           QMessageBox::information(this,"Koniec!","Wygrałes!");
           boardnull(A_,N_);
           pom7=0;
           update();
           break;
        }
        if(pom7==(N_*N_))
        {
                QMessageBox::information(this,"Koniec!","Remis!");
                boardnull(A_,N_);
                pom7=0;
                update();
                break;
        }
        movesAI(A_,N_,pom,x_AI,y_AI);
        pom7++;
        undo_[pom7-1].x=x_AI;
        undo_[pom7-1].y=y_AI;
       if(gamecheck(A_,pom,'O',N_)==1)
        {
           QMessageBox::information(this,"Koniec!","Przegrałeś!");
           boardnull(A_,N_);
           pom7=0;
           update();
           break;
        }
        if(pom7==(N_*N_))
        {
                QMessageBox::information(this,"Koniec!","Remis!");
                boardnull(A_,N_);
                pom7=0;
                update();
                break;
        }
    }
        break;
    case 2:
        x_m=(int)(event->x()-100)/29;
        y_m=(int)(event->y()-90)/29;
        if(x_m>=0 && x_m<N_ && y_m>=0 && y_m<N_&& event->x()-100>0 && event->y()-90>0)
            if(A_[y_m][x_m]==' ')
        {
            if(pom7%2==0)
            {
            A_[y_m][x_m]='X';
            pom7++;
            undo_[pom7-1].x=x_m;
            undo_[pom7-1].y=y_m;
            }
            else
            {
            A_[y_m][x_m]='O';
            pom7++;
            undo_[pom7-1].x=x_m;
            undo_[pom7-1].y=y_m;
            }
            if(pom7%2==1)
            {
            if(gamecheck(A_,pom,'X',N_)==1)
            {
               QMessageBox::information(this,"Koniec!","Wygrywa X!");
               boardnull(A_,N_);
               pom7=0;
               update();
               break;
            }
            }
            else
            if(gamecheck(A_,pom,'O',N_)==1)
             {
              QMessageBox::information(this,"Koniec!","Wygrywa O!");
              boardnull(A_,N_);
              pom7=0;
              update();
              break;
              }
            if(pom7==(N_*N_))
            {
                    QMessageBox::information(this,"Koniec!","Remis!");
                    boardnull(A_,N_);
                    pom7=0;
                    update();
                    break;
            }
        }

          break;

    }
    update();
}



void MainWindow::on_pbWstecz_clicked()
{
    if(gra==1 && pom7>0)
    {
        A_[undo_[pom7-1].y][undo_[pom7-1].x]=' ';
        pom7--;
        A_[undo_[pom7-1].y][undo_[pom7-1].x]=' ';
        pom7--;
        update();
    }
    if(gra==2 && pom7>0)
    {
        A_[undo_[pom7-1].y][undo_[pom7-1].x]=' ';
        pom7--;
        update();
    }
}
