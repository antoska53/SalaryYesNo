#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{

    ui->setupUi(this);
    ui->pushButton_2->installEventFilter(this);
    //but = new QPushButton(this);
    //but->setGeometry(200, 200, 80, 21);
    //but->installEventFilter(this);

}

Widget::~Widget()
{
    delete ui;
}

bool Widget::eventFilter(QObject *watched, QEvent *event){
    if(watched == ui->pushButton_2){
        QEvent::Type type = event->type();

        if(type == QEvent::HoverEnter){

        ui->pushButton_2->setGeometry(std::rand() % 250, std::rand() % 250, 80, 21);
        return true;
        }
    }
    return false;
}

void Widget::on_pushButton_clicked()
{
    //ui->pushButton->setGeometry(100, 100, 80, 21);
    msg.setText("мы так и думали");

    msg.show();
}
