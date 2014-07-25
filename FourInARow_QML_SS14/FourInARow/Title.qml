import QtQuick 2.0
import "style.js" as Style

Column {
    id: header

    property int columns
    property  int rows: 2/columns

    Item {
        id: headSpacer
        height: rows>1 ? Style.unit() * .2 : 0
    }

    Grid {
        width: parent.width
        height: parent.height - 2*headSpacer.height
        columns: header.columns
        rows: header.rows

        Text {
            width: columns<2 ? parent.width : parent.width-titleBoard.width
            height: columns<2 ? parent.height* .4 : parent.height

            text: qsTr("four in a row");
            color: Style.textColor
            font.pixelSize: Style.h1()
            font.bold: true
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter

        }

        Item {
            id: titleBoard
            width: columns<2 ? parent.width : height * .8
            height: columns<2 ? parent.height * .6 : parent.height*.8

            Board {
                dimension: Qt.vector2d(4,4)
            }

        }

    }

}
