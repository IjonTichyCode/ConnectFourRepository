#ifndef QMLMAINWINDOW_H
#define QMLMAINWINDOW_H

#include <QQuickWindow>

/**
 * @brief The QMLMainWindow class is a QQuickWindow which is mapped to the MainWindow QML Type.
 * The MainWindow shows the application.
 */
class QMLMainWindow : public QQuickWindow
{
    Q_OBJECT
public:
    explicit QMLMainWindow(QWindow *parent = 0);

signals:

    /**
     * @brief closing Tells the GUI that the application will be closed
     */
    void closing();

public slots:

    /**
     * @brief setAntialiasing Slot the GUI can call to change the antialiasing option.
     * @param state
     */
    void setAntialiasing(bool state);

    /**
     * @brief setFullscreen Slot the GUI can call to change the fullscreen option
     * @param state
     */
    void setFullscreen(bool state);


    virtual void resizeEvent(QResizeEvent * resizeEvent);

    virtual void close();
    virtual void closeEvent(QQuickCloseEvent * close);

};

#endif // QMLMAINWINDOW_H
