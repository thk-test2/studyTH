#include <QApplication>
#include <QQuickView>
#include <QQmlContext>
#include <QQmlEngine>
#include <QQmlComponent>
#include <QDateTime>
#include <QQuickItem>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QQuickView view;
    view.rootContext()->setContextProperty("currentDateTime", QDateTime::currentDateTime());
    view.setSource(QUrl("qrc:/MyItem.qml"));
    view.show();

//    QQmlEngine* engine = new QQmlEngine;
//    QQmlComponent component(engine, QUrl("qrc:/main.qml"));

//    QObject* myObject = component.create();
//    QQuickItem* item = qobject_cast<QQuickItem*>(myObject);
//    int width = item->width();
//    qDebug() << width;

    return a.exec();
}
