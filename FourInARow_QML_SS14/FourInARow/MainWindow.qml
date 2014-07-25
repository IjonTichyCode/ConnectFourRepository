import QtQuick 2.2
import QtQuick.Window 2.1
import FourInARow 1.0
import "style.js" as Style

QMLMainWindow {
    id: mainWindow
    title: qsTr("four in a row")
    visible: true
    width: 360
    height: 600
    property real unit: height < 2*width ? 0.1 * height : 0.2 * width

    color: Style.backgroundColor

    property MainWindowItem mainWindowItem

    Component.onCompleted: {
        Style.mainWindow = mainWindow

        Style.unit = function() {
            return mainWindow.height < 2*mainWindow.width ? 0.1 * mainWindow.height : 0.2 * mainWindow.width
        }

        Style.h1 = function() { return Style.unit()*.75 }
        Style.h2 = function() { return Style.unit()*.7 }
        Style.h3 = function() { return Style.unit()*.65 }
        Style.h4 = function() { return Style.unit()*55}
        Style.p = function() { return Style.unit()*.5 }
        Style.lineWidth = function() { return Math.ceil(Style.unit() * 0.02) }

        var mainWindowItemComponent = Qt.createComponent("MainWindowItem.qml");
        mainWindowItem = mainWindowItemComponent.createObject(mainWindow);
        mainWindowItem.parentWindow = mainWindow

    }


}
