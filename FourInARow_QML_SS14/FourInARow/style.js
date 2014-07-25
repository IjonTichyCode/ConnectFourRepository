.pragma library

function stdFunction() {
    return 50
}

var buttonColor =  "#444444"
var buttonMouseOverColor =  Qt.darker("steelblue", 1.25)
var buttonPressedColor = Qt.lighter("steelblue", 1.1)
var buttonBorderColor = "silver"
var backgroundColor =  "#202020"
var seperatorColor = "silver"
var seperatorFadeColor = "#30C0C0C0"
var lineWidth = stdFunction
var textColor = "silver"
var textMouseOverColor = Qt.lighter("silver", 1.1)
var textPressedColor = Qt.lighter("silver", 1.5)

var mainWindow

var unit = 15

//var unit = Qt.binding(
//            function() {
//                return mainWindow.height < 2*mainWindow.width ? 0.1 * mainWindow.height : 0.2 * mainWindow.width;
//            }
//)

var h1 = stdFunction
var h2 = stdFunction
var h3 = stdFunction
var h4 = stdFunction
var p = stdFunction
