import QtQuick 2.0
import QtQuick.Controls 1.0
import "style.js" as Style
import FourInARow 1.0

QMLSQLScreen {
    id: sqlScreen
    width: parent.width
    height: parent.height

    signal backClicked

    onQueryOutput: {
        resultTextArea.text = output
    }

    Column {
        anchors.fill: parent

        Item {
            width: parent.width
            height: Style.unit() * 2
        }

        TextField {
            id: queryTextField
            width: parent.width
            height: Style.unit()
        }

        Button {
            text: "query"
            width: parent.width
            height: Style.unit()

            onClicked: sqlScreen.executeQuery(queryTextField.text)
        }

        TextArea {
            id: resultTextArea
            text: "bla\nKex"
            width: parent.width
            height: Style.unit()*6
        }

        Button {

            text: "back"
            width: parent.width
            height: Style.unit()

            onClicked: backClicked()
        }

    }



}
