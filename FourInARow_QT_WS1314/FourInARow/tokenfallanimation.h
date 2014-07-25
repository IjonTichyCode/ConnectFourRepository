#ifndef TOKENFALLANIMATION_H
#define TOKENFALLANIMATION_H

#include <QPropertyAnimation>

/**
 * @brief The TokenFallAnimation class is not used
 */
class TokenFallAnimation : public QPropertyAnimation
{
    Q_OBJECT
public:
    explicit TokenFallAnimation(QObject * target, const QByteArray & propertyName, QObject * parent = 0);

protected:

    virtual void updateState(QAbstractAnimation::State newState, QAbstractAnimation::State oldState);

private:
    int substep;
};

#endif // TOKENFALLANIMATION_H
