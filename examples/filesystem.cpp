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
#include <QtCore/QUrl>

#include <QtCore/QDebug>

class FileTreeItemFactory : public WebItemFactory
{
    public:
        virtual QString pageHeader();
        virtual QString itemTemplate(const QModelIndex &index);
        virtual int itemHeight(const QModelIndex &index);
        virtual QStringList itemClasses(const QModelIndex &index);
};

QString FileTreeItemFactory::pageHeader()
{
    return QString("<style>.header { font-weight: bold; padding: 10px; } "
                   ".item-text { margin: 5px; text-decoration: none; }</style>");
}

QString FileTreeItemFactory::itemTemplate(const QModelIndex & index)
{
	if (index.column() == 0) {
		QUrl url = QUrl::fromLocalFile(index.data(QFileSystemModel::FilePathRole).toString());
    	return QString("<a href='%1' class='item-text' data-role='display'></a>").arg(url.toString());
	} else {
		return QString("<span data-role='display' class='item-text'></span>");
	}
}

int FileTreeItemFactory::itemHeight(const QModelIndex &)
{
    return 20;
}

QStringList FileTreeItemFactory::itemClasses(const QModelIndex &index)
{
    Q_UNUSED(index);
    return QStringList();
}

FileSystemView::FileSystemView(QWidget *parent) :
    QWidget(parent)
{
	setWindowTitle("File System View");

    QTreeView* itemView = new QTreeView(this);
    itemView->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    itemView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    QFileSystemModel* model = new QFileSystemModel(this);
    model->setRootPath("/");

    WebItemDelegate* delegate = new WebItemDelegate(new FileTreeItemFactory, this);
    connect(delegate, SIGNAL(linkClicked(QUrl)), this, SLOT(openLink(QUrl)));

    itemView->setModel(model);
    delegate->setView(itemView);

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(itemView);
}

FileSystemView::~FileSystemView()
{
}

void FileSystemView::openLink(const QUrl& url)
{
    QDesktopServices::openUrl(url);
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    FileSystemView widget;
	widget.resize(640, 480);
    widget.show();
    return app.exec();
}

