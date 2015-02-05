#include "header.h"
#include "ui_Header.h"
#include <QMovie>

Header::Header(QWidget *parent) :
    QWidget(parent),
	movie(new QMovie(":/gif/earthlogo")),
    ui(new Ui::Header)
{
    ui->setupUi(this);
	ui->logoLabel->setMovie(movie);
    movie->start();
}

Header::~Header()
{
    delete ui;
}

void Header::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
        case QEvent::LanguageChange:
            ui->retranslateUi(this);
            break;
        default:
            break;
    }
}
