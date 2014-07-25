#ifndef TOKENFALLSOUND_H
#define TOKENFALLSOUND_H

#include <QTimer>
#include <QSoundEffect>
#include <QTimerEvent>

/**
 * @brief The TokenFallSound class is a QTimer which plays bouncing sounds and a fall sound,
 * timed relative to an absolute time.
 * The object destroys itself, after all sounds are played.
 */
class TokenFallSound : public QTimer
{
    Q_OBJECT
public:
    /**
     * @brief TokenFallSound creates a new TokenFallSound objects and starts playing it.
     * @param slideEffect The SoundEffect imitating the falling of the token
     * @param bounceEffect The SoundEffect imitating a bounce sound, when the token bounces
     * @param msec The absolute time of the whole fall animation
     * @param parent parent QObject
     */
    explicit TokenFallSound(QSoundEffect * slideEffect, QSoundEffect * bounceEffect, int msec, QObject *parent = 0);

protected:
    virtual void timerEvent(QTimerEvent * e);

private:
    int bounceCount;
    int duration;
    QSoundEffect * bounceEffect;
    QSoundEffect * slideEffect;
};

#endif // TOKENFALLSOUND_H
