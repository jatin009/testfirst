// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1

Rectangle {
    width: 420
    height: 360
    color: "blue"


    Rectangle {
        width: parent.width*0.8     //binding
        height: parent.height*0.8
        anchors.centerIn: parent
        color: "red"
    }
    Rectangle {
        width: parent.width*0.5
        height: parent.height*0.5
        anchors.centerIn: parent
        color: "yellow"
    }

//    Text {
//        id: text1
//        anchors.centerIn: parent
//        text: "Hello World"
//        color: "white"
//    }
//    Text {
//        text: qsTr("Dummy Text")

//        anchors.centerIn:parent
//        anchors.top: text1.bottom
//        anchors.left: text1.left
//        color: "white"
//    }
    MouseArea {
        anchors.fill: parent
        onClicked: {
            var x = 3;
            if ( x > 1)
                Qt.quit();
        }
    }
}
