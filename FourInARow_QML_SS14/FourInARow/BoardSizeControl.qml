import QtQuick 2.0
import QtQuick.Controls 1.0
import QtQuick.Controls.Styles 1.1
import "style.js" as Style

Item {
    width: parent.width
    height: Style.unit() * .75

    property int value
    property int maxValue: 9
    property int minValue: 4
    property string label

    signal changed(int value)

    Text {
        color: Style.textColor
        text: label + ": " + value
        width: parent.width * .6
        height: parent.height
        font.pixelSize: Style.p()
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter
    }

    StepButton {
        width: parent.height
        height: parent.height*.8
        anchors.verticalCenter: parent.verticalCenter
        anchors.right: decButton.left

        onClicked: value = value<maxValue ? value+1 : maxValue
        direction: 1
    }

    StepButton {
        id: decButton
        width: parent.height
        height: parent.height*.8
        anchors.verticalCenter: parent.verticalCenter
        anchors.right: parent.right

        onClicked: value = value>minValue ? value-1 : minValue
        direction: -1
    }

}


