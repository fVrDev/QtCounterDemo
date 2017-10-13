#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "bugsscene.h"
#include "bug.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    qmlRegisterType<BugsScene>("BugsScene",1,0,"BugsScene");
    qmlRegisterType<Bug>      ("BugsScene",1,0,"Bug"      );

    QQmlApplicationEngine engine;
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
