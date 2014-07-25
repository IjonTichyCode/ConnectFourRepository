#include "tokenfallsound.h"

TokenFallSound::TokenFallSound(QSoundEffect *slideEffect, QSoundEffect *bounceEffect, int msec, QObject *parent) :
    QTimer(parent),
    bounceCount(0),
    duration(msec),
    bounceEffect(bounceEffect),
    slideEffect(slideEffect)
{
    start(duration*0.43);
    slideEffect->play();
}

void TokenFallSound::timerEvent(QTimerEvent *e) {

    ++bounceCount;
    bounceEffect->play();
    switch (bounceCount) {
    case 1:
        start(duration*0.32);
        break;
    case 2:
        start(duration*0.21);
        break;
    case 3:
        stop();
        slideEffect->stop();
        deleteLater();
        break;
    default:
        deleteLater();
    }
}
