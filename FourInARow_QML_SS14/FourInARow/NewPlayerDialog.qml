import QtQuick 2.0
import QtQuick.Controls 1.2
import "style.js" as Style

Rectangle {
    id: newPlayerDialog

    signal newPlayerClicked(string name, bool isCpu, int level)
    signal cancelClicked

    onNewPlayerClicked: visible = false
    onCancelClicked: visible = false

    height: parent.height-Style.unit()
    width: parent.width
    y: Style.unit()

    color: Style.backgroundColor
    visible: true

    property string levelText: qsTr("level: ") + level
    property int level: 1
    property bool isCpuPlayer: cpuPlayerSwitch.checked
    property int minLevel: 1
    property int maxLevel: 3

    Column {

        anchors.fill: parent

        Text {
            width: parent.width * .84
            anchors.horizontalCenter: parent.horizontalCenter
            height: Style.unit()

            text: qsTr("new player:")
            font.pixelSize: Style.p()
            color: Style.textColor
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignLeft
        }

        TextField {
            id: nameTextField
            width: parent.width * .84
            anchors.horizontalCenter: parent.horizontalCenter
            height: Style.unit()
            font.pixelSize: Style.p()
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignLeft
        }

        OptionsSwitch {
            id: cpuPlayerSwitch
            text: qsTr("artificial player")
            width: parent.width
            height: Style.unit()
        }

        Item {
            id: levelSelection
            width: parent.width * .84
            anchors.horizontalCenter: parent.horizontalCenter
            height: Style.unit()

            Text {
                id: levelLabel
                height: parent.height
                width: parent.width * .68

                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignLeft
                text: levelText
                color: Style.textColor
                font.pixelSize: Style.p()
            }

            StepButton {
                width: parent.height
                height: parent.height*.8
                anchors.verticalCenter: parent.verticalCenter
                anchors.right: decButton.left

                onClicked: level = level<maxLevel ? level+1 : maxLevel
                direction: 1
            }

            StepButton {
                id: decButton
                width: parent.height
                height: parent.height*.8
                anchors.verticalCenter: parent.verticalCenter
                anchors.right: parent.right

                onClicked: level = level>minLevel ? level-1 : minLevel
                direction: -1
            }
        }

        Row {
            id: buttonBar
            width: parent.width
            height: Style.unit()

            SimpleButton {
                label: qsTr("ok")
                height: parent.height
                width: parent.width/2
                onClicked: newPlayerDialog.newPlayerClicked(nameTextField.text, isCpuPlayer, level)
            }

            SimpleButton {
                label: qsTr("cancel")
                height: parent.height
                width: parent.width/2
                onClicked: newPlayerDialog.cancelClicked()
            }
        }
    }


}
