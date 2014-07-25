import QtQuick 2.0
import QtQuick.Controls 1.2
import "style.js" as Style

Rectangle {
    id: newGameScreen
    visible: true

    color: Style.backgroundColor
//    anchors.fill: parent
    width: parent.width
    height: parent.height

    Column {
        anchors.fill: parent

        TextField {
            width: parent.width
            height: parent.height * .1
        }
    }
}
