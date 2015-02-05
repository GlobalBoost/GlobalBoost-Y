#ifndef HEADER_H
#define HEADER_H

#include <QWidget>

namespace Ui {
    class Header;
}

class Header : public QWidget
{
        Q_OBJECT

    public:
        explicit Header(QWidget *parent = 0);
		QMovie *movie;
        ~Header();

    protected:
        void changeEvent(QEvent *e);

    private:
        Ui::Header *ui;
};

#endif // HEADER_H
