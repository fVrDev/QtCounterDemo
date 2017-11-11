import QtQuick 2.7
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3
import BugsScene 1.0

ApplicationWindow
{
    visible: true
    width: 640
    height: 480
    title: qsTr("QtCounterDemo")

    BugsScene
    {
        id: scene
        spaceHeight: 1000
        spaceWidth: 1000
        startSpeed: 150

        onDataChanged: counter.text = rowCount()
    }

    Page
    {
        id: mainPage
        anchors.fill: parent

        Pane
        {
            anchors.top: parent.top
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.bottom: tabBar.top

            SwipeView
            {
                id: swipeView
                anchors.fill: parent
                currentIndex: tabBar.currentIndex

                Item
                {
                    width: swipeView.width
                    height: swipeView.height

                    MouseArea
                    {
                        width: parent.width
                        height: parent.height

                        propagateComposedEvents: true

                        onClicked:
                        {
                            scene.add()
                            mouse.accepted = false
                        }
                    }

                    Label
                    {
                        id: counter

                        anchors.centerIn: parent

                        text: qsTr("No value")
                    }



                    Repeater
                    {
                        model: scene
                        delegate:
                            BugShape
                        {
                            x: (model.posX/scene.spaceWidth) * swipeView.width
                            y: (model.posY/scene.spaceHeight) * swipeView.height
                        }
                    }
                }

                Item
                {
                    width: swipeView.width
                    height: swipeView.height
                }
            }
        }

        TabBar
        {
            id: tabBar
            anchors.bottom: parent.bottom
            width: parent.width
            currentIndex: swipeView.currentIndex

            TabButton {
                text: qsTr("Scene")
            }
            TabButton {
                text: qsTr("Stats")
            }
        }

        RoundButton
        {
            id: close
            text: "Close"
            height: width
            radius: 25

            anchors.top: parent.top
            anchors.right: parent.right

            onClicked: Qt.quit()
        }

        RoundButton
        {
            id: clear
            height: width
            radius: 25
            text: "Clear"
            anchors.right: parent.right
            anchors.top: close.bottom

            onClicked: scene.clear()
        }
    }
}
