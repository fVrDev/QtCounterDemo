import QtQuick 2.0
import Bug 1.0

Bug
{
    property alias x: shape.x
    property alias y: shape.y
    property alias color: shape.color
    property int boundX: 0
    property int boundY: 0

    onRatioXChanged: x = boundX*ratioX
    onRatioYChanged: y = boundY*ratioY

    Rectangle
    {
        id: shape
        width: 5
        height: 5
    }
}
