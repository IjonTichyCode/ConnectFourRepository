import QtQuick 2.0
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.1

import "style.js" as Style

Item {
    id: designSelector
    property int design: 1
    property color color: "#B300FF"

    Text {
        anchors {
            left: parent.left
            top: parent.top
        }
        height: parent.height/2

        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignLeft
        color: Style.textColor

        text: qsTr("board design")
        font.pixelSize: Style.p()
    }

    AspectRatioItem {
        anchors.right: parent.right
        aspectRatio: 1

            Grid {
                anchors.fill: parent
                id: tokenRow
                columns: 2
                rows: 2
                property real tokenEdge: width/2
                layoutDirection: Qt.RightToLeft

                ExclusiveGroup { id: designGroup }

                RadioButton {
                    id: button0
                    exclusiveGroup: designGroup
                    width: tokenRow.tokenEdge
                    height: tokenRow.tokenEdge
                    onCheckedChanged: if (checked) design=0

                    style: RadioButtonStyle {
                        indicator: Token {
                            id: token0
                            color: designSelector.color
                            opacity: button0.checked ? 1 : 0.65
                            design: 0
                            edgeLength: tokenRow.tokenEdge
                            interactive: false
                        }
                    }

                }

                RadioButton {
                    id: button1
                    exclusiveGroup: designGroup
                    width: tokenRow.tokenEdge
                    height: tokenRow.tokenEdge
                    checked: true
                    onCheckedChanged: if (checked) design=1

                    style: RadioButtonStyle {
                        indicator: Token {
                            id: token1
                            color: designSelector.color
                            opacity: button1.checked ? 1 : 0.65
                            design: 1
                            edgeLength: tokenRow.tokenEdge
                            interactive: false
                        }
                    }


                }

                RadioButton {
                    id: button2
                    exclusiveGroup: designGroup
                    width: tokenRow.tokenEdge
                    height: tokenRow.tokenEdge
                    onCheckedChanged: if (checked) design=2

                    style: RadioButtonStyle {
                        indicator: Token {
                            id: token2
                            color: designSelector.color
                            opacity: button2.checked ? 1 : 0.65
                            design: 2
                            edgeLength: tokenRow.tokenEdge
                            interactive: false
                        }
                    }


                }
            }
    }

}
