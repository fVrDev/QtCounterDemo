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

                    Column
                    {
                        anchors.centerIn: parent

                        Button
                        {
                            id: inc
                            text: "Inc"

                            onClicked: caption.text = ++mainPage.bugs_count
                        }

                        Label
                        {
                            id: caption

                            text: qsTr("No value")
                        }

                        Button
                        {
                            id: dec
                            text: "Dec"

                            onClicked:
                            {
                                mainPage.bugs_count = Math.max(0, mainPage.bugs_count - 1)
                                caption.text = (mainPage.bugs_count === 0 ) ? caption.text = "No value"
                                                                            : caption.text = mainPage.bugs_count
                            }
                        }
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
                text: qsTr("Text")
            }
            TabButton {
                text: qsTr("Visual")
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
