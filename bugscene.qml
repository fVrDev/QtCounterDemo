import QtQuick 2.0
import BugsScene 1.0

BugsScene
{
    property alias width: background.width
    property alias height: background.height
    property alias color: background.color

    Rectangle
    {
        id: background
    }
}
