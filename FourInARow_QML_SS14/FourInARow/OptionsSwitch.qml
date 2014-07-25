import QtQuick 2.0
import QtQuick.Controls 1.1
import QtQuick.Controls.Styles 1.1
import "style.js" as Style

CheckBox {
    id: optionsSwitch
    property string text
    property string imageSrc
    property bool antialiasing: true

    style: CheckBoxStyle {

        property real transparency: control.checked ? .9 : .4

        label: Item {
            width: optionsSwitch.width * .85
            height: optionsSwitch.height
            x: optionsSwitch.width*.075

            Text {
                text: optionsSwitch.text
                width: parent.width * 2/3
                height: parent.height
                anchors.left: parent.left
                font.pixelSize: Style.p()
                color: Style.textColor
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignLeft
            }

            Image {
                antialiasing: optionsSwitch.antialiasing
                opacity: transparency

                source: imageSrc
                height: parent.height
                width: parent.height
                anchors.right: parent.right
            }
        }

        indicator: Item {}
    }

}
