import QtQuick 2.0
import "style.js" as Style


Item {
    id: simpleButton
    property string label: "button"
    property real fontSize: Style.h3()

    signal clicked

    Rectangle{
        id: newGameButtonRect
        anchors.fill: parent
//        border.width: 0.004 * parent.width < 1.0 ? 1.0 : 0.004 * parent.width
        border.width: Style.lineWidth()
        border.color: Style.buttonBorderColor
        color: mouseArea.containsMouse ?
                   (mouseArea.pressed ? Style.buttonPressedColor : Style.buttonMouseOverColor ) :
                   Style.buttonColor
    }

    Text {
//        color: "#bfbfbf"
        color: Style.textColor
        text: label
        anchors.centerIn: parent
//        font.pixelSize: 3*parent.height < parent.width ? parent.height* .45 : .15 * parent.width
        font.pixelSize: fontSize
        horizontalAlignment: Text.AlignHCenter
    }

    MouseArea {
        id: mouseArea
        hoverEnabled: true
        anchors.fill: parent

        onClicked: simpleButton.clicked()
    }
}

