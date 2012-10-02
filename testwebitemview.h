#pragma once

#include <QtGui/QWidget>

class QUrl;

class TestWebItemView : public QWidget
{
        Q_OBJECT
        
    public:
        explicit TestWebItemView(QWidget *parent = 0);
        ~TestWebItemView();
        
    public Q_SLOTS:
        void openLink(const QUrl&);

    private:

};


