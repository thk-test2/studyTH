#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "LanguageManager.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    qmlRegisterUncreatableType<Enums>("EnumLanguage", 1, 0, "EnumLanguage", "");

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    LanguageManager *languageManager = new LanguageManager(&engine);
    engine.rootContext()->setContextProperty("LanguageManager", languageManager);

    engine.load(url);

    return app.exec();
}
