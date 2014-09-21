import QtQuick 2.0
import QtQuick.Controls 1.1
import QtQuick.Controls.Styles 1.1
import "style.js" as Style

Column {
    height: Style.unit()* 1.5
    width: parent.width

    property string timeText: time + " min"
    property int time: 1
    property bool checked: timerSwitch.checked
    property int minTime: 1
    property int maxTime: 5

    function setTimer(useTimer, maxTime) {
        timerSwitch.checked = useTimer;
        time = maxTime
    }

    OptionsSwitch {
        id: timerSwitch
        width: parent.width
        height: parent.height/2

        text: qsTr("move timer")
        imageSrc: "/resources/clock.svg"
        padding: 0
    }

    Item {
        id: playerSelection
        width: parent.width
        height: parent.height/2

        Text {
            id: timeLabel
            height: parent.height
            width: parent.width * .68

            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignLeft
            text: timeText
            color: Style.textColor
            font.pixelSize: Style.p()
        }

        StepButton {
            width: parent.height
            height: parent.height*.8
            anchors.verticalCenter: parent.verticalCenter
            anchors.right: decButton.left

            onClicked: time = time<maxTime ? time+1 : maxTime
            direction: 1
        }

        StepButton {
            id: decButton
            width: parent.height
            height: parent.height*.8
            anchors.verticalCenter: parent.verticalCenter
            anchors.right: parent.right

            onClicked: time = time>minTime ? time-1 : minTime
            direction: -1
        }

    }

}

