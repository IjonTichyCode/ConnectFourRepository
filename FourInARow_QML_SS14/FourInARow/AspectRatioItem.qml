import QtQuick 2.0

Item {
    property real aspectRatio: 1
    width: parent.width/parent.height > aspectRatio ? parent.height * aspectRatio : parent.width;
    height: parent.width/parent.height < aspectRatio ? parent.width/ aspectRatio : parent.height;
}
