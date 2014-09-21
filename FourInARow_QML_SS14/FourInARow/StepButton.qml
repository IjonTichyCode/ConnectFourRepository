import QtQuick 2.0
import QtQuick.Controls 1.0
import QtQuick.Controls.Styles 1.1
import "style.js" as Style

Button{
    id: stepButton
    property int direction: 1

    style: ButtonStyle{
        background: Rectangle {
            anchors.fill: parent
            color: control.pressed ? Style.buttonPressedColor : Style.buttonColor
            border.color: Style.buttonBorderColor
            border.width: Style.lineWidth()

            DragArrow {
                anchors.fill: parent
                direction: stepButton.direction
                lineWidth: Style.lineWidth()
            }
        }
    }
}
