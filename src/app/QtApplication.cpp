//
// Created by polydome on 4/14/20.
//

#include "app/model/SpaceGridModel.h"
#include "app/model/OrganismsListModel.h"
#include "app/model/OrganismPropertiesModel.h"
#include "app/adapter/SpaceGridPresenterAdapter.h"
#include "app/adapter/OrganismsListPresenterAdapter.h"
#include "app/adapter/OrganismPropertiesPresenterAdapter.h"
#include <QtGui/QGuiApplication>
#include <QtQml/qqml.h>
#include <QtQml/QQmlApplicationEngine>
#include <QQmlContext>
#include <QDebug>
#include <QtCore/QDir>
#include "QtApplication.h"

const char* BASE_URI = "com.polydome.ekosystem";

void registerTypes() {
    qmlRegisterType<SpaceGridModel>(BASE_URI, 1, 0, "SpaceGridModel");
    qmlRegisterType<OrganismsListModel>(BASE_URI, 1, 0, "OrganismsListModel");
    qmlRegisterType<OrganismPropertiesModel>(BASE_URI, 1, 0, "OrganismPropertiesModel");
    qmlRegisterUncreatableType<SpaceGridPresenterAdapter>(BASE_URI, 1, 0, "SpaceGridPresenter", "");
    qmlRegisterUncreatableType<OrganismsListPresenterAdapter>(BASE_URI, 1, 0, "OrganismsListPresenter", "");
}

void loadLayout(QQmlApplicationEngine& engine, const char* layoutUrl) {
    const QUrl url(layoutUrl);
    engine.load(url);
}

int QtApplication::run(int argc, char **argv, SpaceGridPresenter &spaceGridPresenter,
                       OrganismsListPresenter &organismsListPresenter,
                       OrganismPropertiesPresenter &organismPropertiesPresenter) {
    QGuiApplication app(argc, argv);

    registerTypes();

    QQmlApplicationEngine engine;

    SpaceGridPresenterAdapter spaceGridPresenterAdapter(spaceGridPresenter);
    OrganismsListPresenterAdapter organismsListPresenterAdapter(organismsListPresenter);
    OrganismPropertiesPresenterAdapter organismPropertiesPresenterAdapter(organismPropertiesPresenter);

    engine.rootContext()->setContextProperty(QStringLiteral("spaceGridPresenter"), &spaceGridPresenterAdapter);
    engine.rootContext()->setContextProperty(QStringLiteral("organismsListPresenter"), &organismsListPresenterAdapter);
    engine.rootContext()->setContextProperty(QStringLiteral("organismPropertiesPresenter"), &organismPropertiesPresenterAdapter);

    const char* qrcUrl = "qrc:/main.qml";
    loadLayout(engine, "../src/app/qml/main.qml");

    return app.exec();
}
