#ifndef QMLOPTIONS_H
#define QMLOPTIONS_H

#include <QQuickItem>

/**
 * @brief The QMLOptions class is a QQuickItem which is mapped to the Options QML Type.
 * It sets persisted Options on the GUI Options Panel
 * and receives changes of that options from te Options Panel.
 */
class QMLOptions : public QQuickItem
{
    Q_OBJECT
public:
    explicit QMLOptions(QQuickItem *parent = 0);

signals:
    //signals emitted to set options after the QML Type has been loaded
    void setAntialiasingOption(bool antialiasing);
    void setFullscreenOption(bool fullscreen);
    void setBoardDesignOption(int design);
    void setColor0Option(float color);
    void setColor1Option(float color);
    void setLanguageOption(int language);

public slots:

    void qmlComponentCompleted();

    // slots which are called by the GUI to change options
    void antialiasingSet(bool antialiasing);
    void fullscreenSet(bool fullscreen);
    void boardDesignSet(int design);
    void color0Set(float color);
    void color1Set(float color);
    void languageSet(int language);

private:

    // interrupt short circuit effects while creation of the QML components
    // variable changes while creation may trigger onChange signals, which may
    // manipulate data which should be injected into the qml component afterwards
    bool setupCompleted;
};

#endif // QMLOPTIONS_H
