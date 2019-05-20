#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QTime"
#define LAOYANG 3
#define SHAOYIN 2
#define SHAOYANG 1
#define LAOYIN 0
int genRand(int min,int max)
{Q_ASSERT(min < max); // 加入随机种子。种子是当前时间距离0点0分0秒的秒数。 // 每次启动程序，只添加一次种子，以做到数字真正随机。
    static bool seedStatus;
    if (!seedStatus) { qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));
        seedStatus = true; }
    int nRandom = qrand() % (max - min);
    nRandom = min + nRandom;
    printf("%d,",nRandom);
    return nRandom;


}
int genLeft(int a)//模拟过揲的过程
{
    int b=a%4;
    if(b==0)
        return 4;
    else
        return b;
}

int creatSingleYao(void)
{
   int x,y;//模拟左手和右手的蓍草
   int a,b;//模拟过揲中间量
   int p;
   int count=0;//统计“少”的个数
   int all=50-1;
   for(int i=0;i<3;i++)
   {x=genRand(1,all-1);
   y=all-x;
   p=x+1;
   y=y-1;
   a=genLeft(x);
   b=genLeft(y);
   if(a+b<=5)
   {count++;}
   all=all-a-b-1;
   }
   return count;
}

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

void MainWindow::on_pushButton_clicked()
{ QLabel *lablelist[]={ui->label,ui->label_2,ui->label_3,ui->label_4,ui->label_5,ui->label_6};
    QLabel *infolist[]={ui->label7,ui->label8,ui->label9,ui->label10,ui->label11,ui->label12};

    int a;
    for(int i=0;i<6;i++)
    {a=creatSingleYao();
        if(a==SHAOYANG||a==LAOYANG)
            lablelist[i]->setPixmap(QPixmap(":/img/img/yang.jpg"));
        else
            lablelist[i]->setPixmap(QPixmap(":/img/img/yin.jpg"));
        if(a==LAOYANG||a==LAOYIN)
            infolist[i]->setText("老");
        else
            infolist[i]->setText("少");
    }
}
