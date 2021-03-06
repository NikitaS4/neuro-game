import QtQuick 2.6
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.12


Item {
    id: root
    anchors.centerIn: parent
    width: parent.width * 0.8

    Connections {
        target: Game
        onScSet: {
            scoreText.text = "Score: " + Game.scoreGetRequest()
        }
    }

    Rectangle {
        id:rectPlayMenu

        anchors.fill: parent
        color: "black"
        opacity: 1
    }

    Column {
        id: columnPlayMenu
        anchors.centerIn: rectPlayMenu
        width: rectPlayMenu.width * 0.8
        spacing: 10
        opacity: 0.9

        Button {
            id: singlePlayerButton
            Layout.alignment: Qt.AlignCenter
            opacity: 0.9
            text: "Menu"
            font.pointSize: root.width / 10
            width: parent.width
            onClicked: {
                cppController.mainMenuButtClickd()
                singleplayerMenu.visible = false
                mainMenu.visible = true
            }
        }
        //Button to test signal connected
        //Button {
        //    id: singlePlayerButtonTestScore
        //    Layout.alignment: Qt.AlignCenter
        //    opacity: 0.9
        //    text: "Set 500"
        //    font.pointSize: root.width / 10
        //    width: parent.width
        //    onClicked: {
        //        Game.setScore(500)
        //    }
        //}
        Text {
            id: scoreText
            text: "Score: " + Game.getRequest()
            font.family: "Helvetica"
            font.pointSize: root.width / 15
            width: parent.width
        }
    }
}
