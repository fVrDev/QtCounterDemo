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
            id: mainPane
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
                    visible: tabBar.currentIndex === 0

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
                    visible: tabBar.currentIndex === 1

                    ListView
                    {
                        model: scene
                        anchors.fill: parent
                        spacing: 16
                        delegate:
                            Rectangle
                        {
                            anchors.horizontalCenter: parent.Center
                            width: parent.width - 16
                            height: 64
                            color: "#9999FF"
                        }
                    }
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
            radius: width/2

            anchors.top: parent.top
            anchors.right: parent.right

            onClicked: Qt.quit()
        }

        AcceptedButton
        {
            id: clear
            text: "Clear"
            anchors.right: parent.right
            anchors.top: close.bottom
            height: width

            onClicked: scene.clear()
        }
    }
}
