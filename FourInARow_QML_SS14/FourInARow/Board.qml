import QtQuick 2.0
import FourInARow 1.0

QMLBoard {
    id: board

    dimension: Qt.vector2d(7,6)
    property real aspectRatio: dimension.x/(dimension.y + 2);
    property int design: 0
    width: parent.width/parent.height > aspectRatio ? parent.height * aspectRatio : parent.width;
    height: parent.width/parent.height < aspectRatio ? parent.width/ aspectRatio : parent.height;

    anchors {
        horizontalCenter: parent.horizontalCenter
        bottom: parent.bottom
    }

    tileWidth: width/dimension.x;

    Grid {
        id: boardGrid
        anchors.bottom: parent.bottom
        width: parent.width

        columns: board.dimension.x
        rows: board.dimension.y


        Repeater {
            model: boardGrid.columns * boardGrid.rows
            BoardTile {
                edgeLength: boardGrid.width/boardGrid.columns
                design: board.design
            }
        }
    }

    grid: boardGrid

//    Component.onCompleted: {
//        grid = boardGrid
//    }

}
