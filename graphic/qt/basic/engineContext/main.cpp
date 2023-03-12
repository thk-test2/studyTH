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
    view.setSource(QUrl("qrc:/main.qml"));
    QQmlComponent textComponent(view.engine(), QUrl("qrc:/MyItem.qml"),
                                QQmlComponent::PreferSynchronous);
    if(textComponent.isError())
        qDebug() << textComponent.errors();

    QQuickItem* item = qobject_cast<QQuickItem*>(textComponent.create());
    item->setParentItem(view.rootObject());

    view.show();

    /* https://doc.qt.io/qt-5/qqmlcomponent.html#create
     If the object being created from this component is a visual item, it must
    have a visual parent, which can be set by calling
    QQuickItem::setParentItem(). See \l {Concepts - Visual Parent in Qt Quick}
    for more details.

    \sa QQmlEngine::ObjectOwnership
    */
    return a.exec();
}
