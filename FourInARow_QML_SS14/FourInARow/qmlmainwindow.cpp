#include <QDebug>
#include "qmlmainwindow.h"


QMLMainWindow::QMLMainWindow(QWindow *parent) :
    QQuickWindow(parent)
{
    QSurfaceFormat format;
    format.setSamples(16);
    setFormat(format);
    qDebug() << "Constructed QMLMainWindow";

    // old syntax needed, because of bug:
    // https://bugreports.qt-project.org/browse/QTBUG-36453?page=com.atlassian.jira.plugin.system.issuetabpanels:all-tabpanel
    connect(this, SIGNAL(closing(QQuickCloseEvent*)), this, SLOT(closeEvent(QQuickCloseEvent *)));
}

void QMLMainWindow::setAntialiasing(bool state)
{
    QSurfaceFormat format;
    format.setSamples(state ? 16 : 1);
    setFormat(format);
    qDebug() << "changed Antialiasing:" << state;
}

void QMLMainWindow::setFullscreen(bool state)
{
    if (state) {
        showFullScreen();
    }else{
        showNormal();
    }
}

void QMLMainWindow::close()
{
    qDebug() << "close";
    QQuickWindow::close();
}

void QMLMainWindow::closeEvent(QQuickCloseEvent *close)
{
    this->close();
}
