import QtQuick 2.0
import QtQuick.Controls 2.2

Item
{
    property alias text: mainBtn.text

    width: 64

    signal clicked();

    property int m_encounter: 0;

    RoundButton
    {
        id: mainBtn
        anchors.centerIn: parent.Center
        height: width
        radius: width/2
        z: 1

        onClicked: ++m_encounter;
    }

    RoundButton
    {
        id: acceptBtn
        anchors.centerIn: parent.Center
        width: mainBtn.width
        height: width
        radius: width/2
        z: 0

        onClicked:
        {
            parent.clicked();
            ++m_encounter;
        }
    }

    states:
        State
    {
         name: "down"; when: m_encounter % 2 > 0
         PropertyChanges
         {
             target: acceptBtn;
             text: "Ok"
             y: mainBtn.y + mainBtn.height/2 + acceptBtn.height/2 + 4;
         }
         PropertyChanges
         {
             target: mainBtn;
             text: "Oh, NO"
         }
    }

    transitions:
        Transition
    {
         from: ""; to: "down"; reversible: true
         NumberAnimation
         {
             properties: "y";
             duration: 200;
             easing.type: Easing.InOutQuad
         }
    }
}
