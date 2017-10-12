import QtQuick 2.7
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3

ApplicationWindow
{
    visible: true
    width: 640
    height: 480
    title: qsTr("QtCounterDemo")

    Page
    {
        id: mainPage
        anchors.fill: parent

        property int bugs_count: 0

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
                            caption.text = ++mainPage.bugs_count
                            mouse.accepted = false
                        }
                    }

                    Label
                    {
                        id: caption

                        anchors.centerIn: parent

                        text: qsTr("No value")
                    }

                }
                Item
                {
                    width: swipeView.width
                    height: swipeView.height

                    Label
                    {
                        anchors.centerIn: parent
                        text: qsTr("Empty")
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

            anchors.top: parent.top
            anchors.right: parent.right

            onClicked: Qt.quit()
        }
    }
}
