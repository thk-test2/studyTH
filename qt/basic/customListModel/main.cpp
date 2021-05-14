#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "mydatamodel.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    // QAbstractListModel 서브클래싱 모델 객체 생성.
    MyDataModel *model = new MyDataModel();

    // 모델 아이템 생성.
    QObject * item0 = new QObject();
    item0->setProperty("title", "There's Nothing Holdin' Me Back");
    item0->setProperty("artistName", "Shawn Mendes");

    QObject * item1 = new QObject();
    item1->setProperty("title", "Shape of You");
    item1->setProperty("artistName", "Ed Sheeran");
    //~ 모델 아이템 생성.

    // 모델에 아이템 삽입.
    model->append(item0);
    model->append(item1);
    //~ 모델에 아이템 삽입.

    engine.rootContext()->setContextProperty("myModel", model);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
