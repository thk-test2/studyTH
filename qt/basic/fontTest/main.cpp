#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QFontDatabase>
#include <QStandardPaths>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

//    int f1 = QFontDatabase::addApplicationFont(":/fonts/font/Roboto/Roboto-Regular.ttf");
//    int f2 = QFontDatabase::addApplicationFont(":/fonts/font/Roboto/Roboto-Thin.ttf");
//    int f3 = QFontDatabase::addApplicationFont(":/fonts/font/Roboto/Roboto-Bold.ttf");
    int f1 = QFontDatabase::addApplicationFont(qApp->applicationDirPath()+"/font/Roboto/Roboto-Regular.ttf");
    int f2 = QFontDatabase::addApplicationFont(qApp->applicationDirPath()+"/font/Roboto/Roboto-Thin.ttf");
    int f3 = QFontDatabase::addApplicationFont(qApp->applicationDirPath()+"/font/Roboto/Roboto-Bold.ttf");
//    f1 = QFontDatabase::addApplicationFont(qApp->applicationDirPath()+"/font/Noto_Sans_KR/NotoSansKR-Regular.otf");
//    f2 = QFontDatabase::addApplicationFont(qApp->applicationDirPath()+"/font/Noto_Sans_KR/NotoSansKR-Thin.otf");
//    f3 = QFontDatabase::addApplicationFont(qApp->applicationDirPath()+"/font/Noto_Sans_KR/NotoSansKR-Bold.otf");
    qDebug() << qApp->applicationDirPath();
//    QStringList path(QStandardPaths::standardLocations(QStandardPaths::FontsLocation));
    qDebug() << QStandardPaths::standardLocations(QStandardPaths::FontsLocation);
    qDebug() << f1 << f2 << f3;

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
