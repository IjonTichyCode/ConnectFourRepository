import QtQuick 2.0
import QtQuick.Controls 1.1
import QtQuick.Controls.Styles 1.1
import "style.js" as Style

Button {
    id: closeButton
    width: Style.unit()
    height: Style.unit()

    style: ButtonStyle {
        background: Rectangle {
            id: background
            width: closeButton.width
            height: closeButton.height
            color: Style.buttonColor
            border.width: Style.lineWidth()
            border.color: Style.buttonBorderColor

            Rectangle {
                id: line0
                height: Style.unit()*.1
                width: Style.unit()
                anchors.centerIn: parent
                color: "red"
                smooth: true

                transform: Rotation {
                    angle: 45
                    origin.x: line0.width/2
                    origin.y: line0.height/2
                }

            }

            Rectangle {
                id: line1
                height: Style.unit()*.1
                width: Style.unit()
                anchors.centerIn: parent
                color: "red"
                smooth: true

                transform: Rotation {
                    angle: -45
                    origin.x: line1.width/2
                    origin.y: line1.height/2
                }

            }


//            gradient: Gradient {
//                GradientStop { position: 0 ; color: control.pressed ? "#ccc" : "#eee" }
//                GradientStop { position: 1 ; color: control.pressed ? "#aaa" : "#ccc" }
//            }
        }
    }
}
