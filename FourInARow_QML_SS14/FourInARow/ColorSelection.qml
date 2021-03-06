import QtQuick 2.0
import QtQuick.Controls 1.0
import QtQuick.Controls.Styles 1.0

import "style.js" as Style

Column {

    property color color0: Qt.hsla(slider1.value, 1.0, 0.5, 1.0)
    property color color1: Qt.hsla(slider2.value, 1.0, 0.5, 1.0)

    property real color0hue: slider1.value
    property real color1hue: slider2.value

    function setColor0(color) {
        slider1.value = color;
    }
    function setColor1(color) {
        slider2.value = color;
    }

    Text {
        anchors {
            left: parent.left
        }
        height: parent.height/2
        width: parent.width

        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignLeft
        color: Style.textColor

        text: qsTr("token colors")
        font.pixelSize: Style.p()
    }

    Slider {
        id: slider1
        width: parent.width / 1.05
        height: parent.width * .15
        anchors.horizontalCenter: parent.horizontalCenter
        minimumValue: 0
        maximumValue: .9
        stepSize: .1
        value: .3
        z:1
        property real lastValue: .3

        onValueChanged: {
            if (slider2 && value==slider2.value) {
                value = lastValue
            }else{
                lastValue=value
            }
        }

        style: SliderStyle {
            groove: Item{}

            handle: Column {
                width: slider1.width * .1
                height: slider1.height

                Rectangle {
                    height: parent.height * 3/4
                    width: parent.width * 1.5
                    anchors.horizontalCenter: parent.horizontalCenter
                    color: Qt.hsla(control.value, 1.0, 0.5, 1.0)
                    border.color: Style.buttonBorderColor
                    border.width: Style.lineWidth()

                    Text {
                        anchors.fill: parent
                        verticalAlignment: Text.AlignVCenter
                        horizontalAlignment: Text.AlignHCenter
                        color: "white"
                        text: "1"
                        font.pixelSize: Style.p()
                    }
                }
                Rectangle {
                    height: parent.height * 1/4
                    width: Style.lineWidth()*2
                    color: Style.buttonBorderColor
                    anchors.horizontalCenter: parent.horizontalCenter
                }
            }

        }

    }

    Row{
        width: parent.width / 1.05
        height: parent.width / 40
        anchors.horizontalCenter: parent.horizontalCenter

        Repeater {
            model: 10
            Rectangle {
                color: Qt.hsla(index/10.0, 1.0, 0.5, 1.0)
                height: parent.width /4
                width: parent.width/10
                anchors.verticalCenter: parent.verticalCenter
            }
        }
    }

    Slider {
        id: slider2
        width: parent.width / 1.05
        height: parent.width * .15
        anchors.horizontalCenter: parent.horizontalCenter
        minimumValue: 0
        maximumValue: .9
        stepSize: .1
        value: .7
        property real lastValue: .7
        z:1

        onValueChanged: {
            if (slider1 && value==slider1.value) {
                value = lastValue
            }else{
                lastValue=value
            }
        }

        style: SliderStyle {
            groove: Item{}

            handle: Column {
                width: slider2.width * .1
                height: slider2.height

                Rectangle {
                    height: parent.height * 1/4
                    width: Style.lineWidth()*2
                    color: Style.buttonBorderColor
                    anchors.horizontalCenter: parent.horizontalCenter
                }

                Rectangle {
                    height: parent.height * 3/4
                    width: parent.width * 1.5
                    anchors.horizontalCenter: parent.horizontalCenter
                    color: Qt.hsla(control.value, 1.0, 0.5, 1.0)
                    border.color: Style.buttonBorderColor
                    border.width: Style.lineWidth()

                    Text {
                        anchors.fill: parent
                        verticalAlignment: Text.AlignVCenter
                        horizontalAlignment: Text.AlignHCenter
                        color: "white"
                        text: "2"
                        font.pixelSize: Style.p()
                    }
                }

            }

        }

    }

}
