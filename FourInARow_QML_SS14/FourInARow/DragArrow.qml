import QtQuick 2.0

//Item {
//    id: drawMask
//    clip: true

//    property int direction: 1
//    property color color: "silver"

//    width: 2*height

//    Item {
//        id: arrowCanvas
//        width: parent.width
//        height: parent.height*2

//        anchors.horizontalCenter: parent.horizontalCenter
//        y: -direction * parent.height
//        //anchors.bottom: parent.bottom

//        Rectangle {
//            id: rotRect
//            width: .6 * parent.width
//            height: .6 * parent.height
//            anchors.centerIn: parent
//            color: "transparent"
//            smooth: true

//            //z:3

//            border {
//                color: drawMask.color
//                width: rotRect.width * .1
//            }

//            transform: Rotation {
//                angle: 45
//                origin.x: rotRect.width/2
//                origin.y: rotRect.height/2
//            }

//        }


//    }


//}

Item {
    id: dragArrow

    property int direction: 1
    property color color: "silver"
    property real size: .5
    property real lineWidth: 3

    Item {
        id: drawMask
        height: parent.width/2
        width: parent.width
//        color: "red"
        clip: true
        y: direction<0 ? (parent.height - height)*.75 : (parent.height-height)*.25

        Rectangle {
            id: arrow
            anchors.horizontalCenter: parent.horizontalCenter
            width: parent.width * size
            height: parent.width * size
            y: direction * height/2

            color: "transparent"
            border.color: dragArrow.color
            border.width: lineWidth

            transform: Rotation {
                angle: 45
                origin.x: arrow.width/2
                origin.y: arrow.height/2
            }

        }
    }
}
