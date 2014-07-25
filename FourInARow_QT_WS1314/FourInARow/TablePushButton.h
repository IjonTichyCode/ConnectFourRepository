#ifndef TABLEPUSHBUTTON_H
#define TABLEPUSHBUTTON_H

#include <QPushButton>

/**
 * @brief The TablePushButton class implements a custome push button to be integrated
 * into a TableView. It emits a special SIGNAL emitIndex, when clicked, which can be used to identify its row.
 */
class TablePushButton : public QPushButton
{
    Q_OBJECT
public:
    explicit TablePushButton(int index, const QString & text, QWidget * parent =0);

signals:
    /**
     * @brief emitIndex Signal emittes the index used to create this object, when clicked.
     * @param index
     */
    virtual void emitIndex(int index);

protected slots:
    /**
     * @brief wasClicked is an helper method to emit the emitIndex SIGNAL
     */
    virtual void wasClicked();

private:
    int index;
};

#endif // TABLEPUSHBUTTON_H
