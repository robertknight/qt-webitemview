#include "filesystem.h"

#include "WebItemDelegate.h"

#include <QtGui/QApplication>
#include <QtGui/QStringListModel>
#include <QtGui/QTreeView>
#include <QtGui/QVBoxLayout>
#include <QtGui/QTableView>
#include <QtGui/QHeaderView>
#include <QtGui/QFileSystemModel>
#include <QtGui/QDesktopServices>

#include <QtCore/QTime>

#include <QtCore/QDebug>

class TestItemFactory : public WebItemFactory
{
    public:
        virtual QString pageHeader();
        virtual QString itemTemplate(const QModelIndex &index);
        virtual int itemHeight(const QModelIndex &index);
        virtual QStringList itemClasses(const QModelIndex &index);
};

QString TestItemFactory::pageHeader()
{
    return QString("<style>.item-selected { font-style:italic; } .header { font-weight: bold; padding:10px; } "
                   ".item-text { margin : 5px; }</style>");
}

QString TestItemFactory::itemTemplate(const QModelIndex &)
{
    return QString("<span data-role='display' class='item-text'></span>");
}

int TestItemFactory::itemHeight(const QModelIndex &)
{
    return 40;
}

QStringList TestItemFactory::itemClasses(const QModelIndex &index)
{
    Q_UNUSED(index);
    return QStringList();
}

TestWebItemView::TestWebItemView(QWidget *parent) :
    QWidget(parent)
{
    QTreeView* itemView = new QTreeView(this);
    itemView->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    itemView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    QFileSystemModel* model = new QFileSystemModel(this);
    model->setRootPath("/");

    WebItemDelegate* delegate = new WebItemDelegate(new TestItemFactory, this);
    connect(delegate, SIGNAL(linkClicked(QUrl)), this, SLOT(openLink(QUrl)));

    itemView->setModel(model);
    delegate->setView(itemView);

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(itemView);
}

TestWebItemView::~TestWebItemView()
{
}

void TestWebItemView::openLink(const QUrl& url)
{
    QDesktopServices::openUrl(url);
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    TestWebItemView w;
    w.show();
    return a.exec();
}

