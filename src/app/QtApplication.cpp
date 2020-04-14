//
// Created by polydome on 4/14/20.
//

#include "app/model/SpaceGridModel.h"
#include "app/adapter/SpaceGridPresenterAdapter.h"
#include <QtGui/QGuiApplication>
#include <QtQml/qqml.h>
#include <QtQml/QQmlApplicationEngine>
#include <QQmlContext>
#include "QtApplication.h"

const char* BASE_URI = "com.polydome.ekosystem";

void registerTypes() {
    qmlRegisterType<SpaceGridModel>(BASE_URI, 1, 0, "SpaceGridModel");
    qmlRegisterUncreatableType<SpaceGridPresenterAdapter>(BASE_URI, 1, 0, "SpaceGridPresenter", "");
}

void loadLayout(QQmlApplicationEngine& engine, const char* layoutUrl) {
    const QUrl url(layoutUrl);
    engine.load(url);
}

int QtApplication::run(int argc, char **argv, SpaceGridPresenter &spaceGridPresenter) {
    QGuiApplication app(argc, argv);

    registerTypes();

    QQmlApplicationEngine engine;

    SpaceGridPresenterAdapter spaceGridPresenterAdapter(spaceGridPresenter);
    engine.rootContext()->setContextProperty(QStringLiteral("spaceGridPresenter"), &spaceGridPresenterAdapter);

    const char* qrcUrl = "qrc:/main.qml";
    loadLayout(engine, "../src/app/qml/main.qml");

    return app.exec();
}
