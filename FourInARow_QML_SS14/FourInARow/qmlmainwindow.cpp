#include <QDebug>
#include "qmlmainwindow.h"
#include "GameDataModel.h"
#include "FIARApplicationSetup.h"


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

    FIARApplicationSetup & appSetup = GameDataModel::getInstance()->getAppSetup();
    setWidth(appSetup.width > 150 ? appSetup.width : 360);
    setHeight(appSetup.height > 150 ? appSetup.height : 600);
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

void QMLMainWindow::resizeEvent(QResizeEvent *resizeEvent)
{
    FIARApplicationSetup & appSetup = GameDataModel::getInstance()->getAppSetup();
    appSetup.width = resizeEvent->size().width();
    appSetup.height = resizeEvent->size().height();
    QQuickWindow::resizeEvent(resizeEvent);
}

void QMLMainWindow::close()
{
    closing();
    GameDataModel::getInstance()->saveAppSetup();
    qDebug() << "close";
    QQuickWindow::close();
}

void QMLMainWindow::closeEvent(QQuickCloseEvent *close)
{
    this->close();
}
