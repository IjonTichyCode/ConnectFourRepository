import QtQuick 2.0
import QtQuick.Controls 1.1
import QtQuick.Controls.Styles 1.1
import "style.js" as Style

CheckBox {
    id: optionsSwitch
    property string text
    property string imageSrc
    property bool antialiasing: true
    property real padding: .075

    style: CheckBoxStyle {

        property real transparency: control.checked ? .9 : .4

        label: Item {
            width: optionsSwitch.width * (1-optionsSwitch.padding*2)
            height: optionsSwitch.height
            x: optionsSwitch.width* optionsSwitch.padding

            Text {
                text: optionsSwitch.text
                width: parent.width * 2/3
                height: parent.height
                anchors.left: parent.left
                font.pixelSize: Style.p()
                color: Style.textColor
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignLeft
            }

            Row {
                width: parent.height * 1.75
                height: parent.height
                anchors.right: parent.right

                Image {
                    antialiasing: optionsSwitch.antialiasing
                    opacity: transparency

                    source: imageSrc
                    height: parent.height
                    width: parent.height
                }

                Item {
                    height: parent.height
                    width: parent.height / 4
                }

                Item {
                    width: parent.height/2
                    height: parent.height/2
                    anchors.bottom: parent.bottom
                    Rectangle {
                        width: parent.width * .8
                        height: parent.height * .8
                        anchors.centerIn: parent
                        color: "transparent"
                        border.color: Style.seperatorColor
                        border.width: Style.lineWidth()
                    }

                    Image {
                        id: hook
                        antialiasing: optionsSwitch.antialiasing
                        opacity: .9
                        visible: control.checked ? true : false

                        source: "resources/hook.svg"
                        width: parent.height
                        height: parent.height
            //            anchors.bottom: parent.bottom
            //            anchors.right: parent.right
                    }
                }


            }

        }

        indicator: Item{}
    }

}
