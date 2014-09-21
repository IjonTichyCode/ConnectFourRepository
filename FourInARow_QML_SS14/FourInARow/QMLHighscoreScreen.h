#ifndef QMLHIGHSCORESCREEN_H
#define QMLHIGHSCORESCREEN_H

#include <QQuickItem>

/**
 * @brief The QMLHighscoreScreen class is a QQuickItem which is mapped to the HighScoreScreen QML-Type.
 * It fills the qml with highscore entries from the GameDataModel.
 */
class QMLHighscoreScreen : public QQuickItem
{
    Q_OBJECT
public:
    explicit QMLHighscoreScreen(QQuickItem *parent = 0);

signals:

    /**
     * @brief addEntry Adds one Entry to the visual highscore
     * @param player The player name
     * @param wins
     * @param losses
     * @param ratio Ratio between wins and losses of this player
     */
    void addEntry(QString player, int wins, int losses, qreal ratio);

    /**
     * @brief clear Delete all visible player entries on the Screen
     */
    void clear();


public slots:

    /**
     * @brief populate populates the qml type mapped to this with all
     * player entries from the GameDataModel highscore
     */
    void populate();

};

#endif // QMLHIGHSCORESCREEN_H
