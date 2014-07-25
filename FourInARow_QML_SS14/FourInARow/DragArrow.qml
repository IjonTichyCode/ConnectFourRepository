import QtQuick 2.0

Item {
    id: drawMask
    clip: true

    property int direction: 1
    property color color: "silver"

    width: 2*height

    Item {
        id: arrowCanvas
        width: parent.width
        height: parent.height*2

        anchors.horizontalCenter: parent.horizontalCenter
        y: -direction * parent.height
        //anchors.bottom: parent.bottom

        Rectangle {
            id: rotRect
            width: .6 * parent.width
            height: .6 * parent.height
            anchors.centerIn: parent
            color: "transparent"
            smooth: true

            //z:3

            border {
                color: drawMask.color
                width: rotRect.width * .1
            }

            transform: Rotation {
                angle: 45
                origin.x: rotRect.width/2
                origin.y: rotRect.height/2
            }

        }


    }


}
