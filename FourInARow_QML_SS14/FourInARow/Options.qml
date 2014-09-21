import QtQuick 2.0
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.2
import QtQuick.Dialogs 1.0
import "style.js" as Style

import FourInARow 1.0

QMLOptions  {
    id: optionsRect
    width: Style.unit()* 7 > parent.width ? parent.width : Style.unit() *7
    height: Style.unit()*9

    anchors.horizontalCenter: parent.horizontalCenter

    property real optionsActiveY: 0
    property real optionsInactiveY: Style.unit() * -8

    property bool optAntialiasing: true
    property bool optFullscreen: false
    property int optDesign: designSelector.design
    property color optColor0: colorSelection.color0
    property color optColor1: colorSelection.color1
    property real optColor0Hue: colorSelection.color0hue
    property real optColor1Hue: colorSelection.color1hue
    property int optLanguage: germanSwitch.checked ? 0 : 1

    property color textColor: optionsMouseArea.containsMouse ?
                                  (optionsMouseArea.pressed ? Style.buttonPressedColor : Style.buttonMouseOverColor ) :
                                  Style.textColor

    // loading options (receiving signals from backing C++ object)
    onSetAntialiasingOption: antialiasingSwitch.checked = antialiasing
    onSetFullscreenOption: fullscreenSwitch.checked = fullscreen
    onSetBoardDesignOption: designSelector.setDesign(design)
    onSetColor0Option: colorSelection.setColor0(color)
    onSetColor1Option: colorSelection.setColor1(color)
    onSetLanguageOption: {
        if (language==0) {
            germanSwitch.checked = true
        }else{
            englishSwitch.checked = true
        }
    }

    // changing options (calling slots on backing C++ object)
    onOptColor0HueChanged: color0Set(optColor0Hue)
    onOptColor1HueChanged: color1Set(optColor1Hue)
    onOptAntialiasingChanged: antialiasingSet(optAntialiasing)
    onOptFullscreenChanged: fullscreenSet(optFullscreen)
    onOptDesignChanged: boardDesignSet(optDesign)
    onOptLanguageChanged: languageSet(optLanguage)

    states: [
        State {
            name: "ACTIVE"
            PropertyChanges {
              target: leftDragger
              direction: 1
            }
            PropertyChanges {
              target: rightDragger
              direction: 1
            }
            PropertyChanges {
              target: optionsRect
              y: optionsActiveY
            }
        },
        State {
            name: "INACTIVE"
            PropertyChanges {
              target: leftDragger
              direction: -1
            }
            PropertyChanges {
              target: rightDragger
              direction: -1
            }
            PropertyChanges {
              target: optionsRect
              y: optionsInactiveY
            }
        }

    ]

    transitions: Transition {
            NumberAnimation {
                properties: "y"
                easing.type: Easing.InOutQuad
                duration: 250
            }
    }

    state: "INACTIVE"
    y: optionsInactiveY



    Rectangle {
        anchors.top: parent.top
        height: parent.height
        anchors.horizontalCenter: parent.horizontalCenter
        width: parent.width
        color: "black"

        Column {

            anchors.fill: parent

            OptionsSwitch {
                id: fullscreenSwitch;
                height: Style.unit() * .85
                width: parent.width
                imageSrc: "/resources/fullscreen.svg"
                text: qsTr("fullscreen")
                onCheckedChanged: {
                    optionsRect.optFullscreen = checked
                }
            }

            Seperator {
                height: Style.unit() * .15
            }

            OptionsSwitch {
                id: antialiasingSwitch
                height: Style.unit() * .85
                width: parent.width
                imageSrc: "/resources/antialias.png"
                text: qsTr("antialiasing")
                checked: true
                antialiasing: false
                onCheckedChanged: {
                    optionsRect.optAntialiasing = checked
                }
            }

            Seperator {
                height: Style.unit() * .15
            }

            Row {
                height: Style.unit() * .85
                width: parent.width * .85
                anchors.horizontalCenter: parent.horizontalCenter

                OptionsSwitch {
                    id: englishSwitch
                    height: Style.unit() * .85
                    width: parent.width/2
                    onCheckedChanged: germanSwitch.checked = !checked
                    imageSrc: "/resources/uk.svg"
                    text: qsTr("")
                }

                OptionsSwitch {
                    id: germanSwitch
                    height: Style.unit() * .85
                    width: parent.width/2
                    onCheckedChanged: englishSwitch.checked = !checked
                    imageSrc: "/resources/de.svg"
                    text: qsTr("")
                }
            }



            Seperator {
                height: Style.unit() * .15
            }

            DesignSelector {
                id: designSelector
                height: Style.unit() * 1.7
                width: parent.width * .85
                anchors.horizontalCenter: parent.horizontalCenter
                color: optColor0
            }

            Seperator {
                height: Style.unit() * .15
            }

            ColorSelection {
                id: colorSelection
                height: Style.unit() * 1.7
                width: parent.width * .85
                anchors.horizontalCenter: parent.horizontalCenter
            }

        }

        DragArrow {
            id: leftDragger
            anchors {
                left: parent.left
                bottom: parent.bottom
            }
            height: parent.height > 2*parent.width ? parent.width/4.5 : parent.height/9
            width: 1.5*height

            color: textColor
            lineWidth: Style.lineWidth()*2
        }

        DragArrow {
            id: rightDragger
            anchors {
                bottom: parent.bottom
                right: parent.right
            }
            height: leftDragger.height
            width: 1.5*height

            color: textColor
            lineWidth: Style.lineWidth()*2
        }

        Text {
            text: qsTr("options")
            anchors {
                bottom: parent.bottom
                left: leftDragger.right
                right: rightDragger.left
                top: leftDragger.top
            }

    //        color: optionsMouseArea.containsMouse ?
    //                   (optionsMouseArea.pressed ? Style.textPressedColor : Style.textMouseOverColor ) :
    //                   Style.textColor
            color: textColor

            font.pixelSize: Style.p()

            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }

        MouseArea {
            id: optionsMouseArea
            hoverEnabled: true
            anchors {
                bottom: parent.bottom
                left: parent.left
                right: parent.right
                top: leftDragger.top
            }

            onClicked: {
                if (optionsRect.state == "ACTIVE")
                    optionsRect.state = "INACTIVE"
                else
                    optionsRect.state = "ACTIVE"
            }
        }
    }

}
