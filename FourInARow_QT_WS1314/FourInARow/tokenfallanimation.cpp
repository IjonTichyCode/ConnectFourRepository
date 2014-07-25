#include "tokenfallanimation.h"
#include <QDebug>

TokenFallAnimation::TokenFallAnimation(QObject * target, const QByteArray & propertyName, QObject * parent):
    QPropertyAnimation(target, propertyName, parent),
    substep(0)
{

}

void TokenFallAnimation::updateState(QAbstractAnimation::State newState, QAbstractAnimation::State oldState)
{
    QPropertyAnimation::updateState(newState, oldState);

    if (newState == QAbstractAnimation::State::Stopped && oldState== QAbstractAnimation::State::Running && substep<2) {
        ++substep;
        int storeStart = startValue().value<int>();
        setStartValue(endValue());
        setEndValue(startValue().value<int>()/2);
        setDuration(duration()/1.5);
        start(substep>1 ? QAbstractAnimation::DeleteWhenStopped : QAbstractAnimation::KeepWhenStopped );
    }

    qDebug() << "updateState";
}
