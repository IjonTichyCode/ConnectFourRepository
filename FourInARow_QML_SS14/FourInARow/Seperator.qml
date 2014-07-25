import QtQuick 2.0
import QtGraphicalEffects 1.0
import "style.js" as Style

Item {
    height: Style.unit() * .25
    width: parent.width
    LinearGradient  {

        start: Qt.point(0,height/2)
        end: Qt.point(width,height/2)
        width: parent.width
        height: Style.lineWidth()
        anchors.verticalCenter: parent.verticalCenter

        gradient: Gradient {
            GradientStop { position: 0.0; color: Style.seperatorFadeColor }
            GradientStop { position: 0.18; color: Style.seperatorColor }
            GradientStop { position: 0.82; color: Style.seperatorColor }
            GradientStop { position: 1.0; color: Style.seperatorFadeColor }
        }

    }

}

