#ifndef QMLMAINWINDOW_H
#define QMLMAINWINDOW_H

#include <QQuickWindow>

class QMLMainWindow : public QQuickWindow
{
    Q_OBJECT
public:
    explicit QMLMainWindow(QWindow *parent = 0);

signals:
//    virtual void closing(QQuickCloseEvent * close);

public slots:
    void setAntialiasing(bool state);
    void setFullscreen(bool state);

    virtual void close();
    virtual void closeEvent(QQuickCloseEvent * close);

};

#endif // QMLMAINWINDOW_H
