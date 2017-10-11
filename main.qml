import QtQuick 2.7
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3

ApplicationWindow
{
    visible: true
    width: 640
    height: 480
    title: qsTr("QtCounterDemo")

    property int index: 0

    Label
    {
        id: label
        anchors.centerIn: parent
        text: qsTr("No value")
    }

    Column
    {
        anchors.bottom: parent.bottom
        width: parent.width

        Button
        {
            width: parent.width
            text: qsTr("Inc")

            onClicked: label.text = ++index
        }

        Button
        {
            width: parent.width
            text: qsTr("Close")

            onClicked: Qt.quit()
        }
    }
}
