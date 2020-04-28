cmake_minimum_required(VERSION 3.5)

project(ekosystem LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Core Quick REQUIRED)

add_executable(ekosystem
        src/main.cpp
        src/domain/body/body.cpp
        src/domain/body/bodyregistry.cpp
        src/domain/logging/ekolog.cpp
        src/domain/organism/human.cpp
        src/domain/organism/infobundle.cpp
        src/domain/organism/organism.cpp
        src/domain/organism/virus.cpp
        src/domain/simulation/simulation.cpp
        src/domain/space/space.cpp
        src/domain/space/vicinity.cpp
        src/domain/space/vicinityprovider.cpp
        src/domain/body/body.h
        src/domain/body/bodyregistry.h
        src/domain/logging/ekolog.h
        src/domain/organism/human.h
        src/domain/organism/infobundle.h
        src/domain/organism/organism.h
        src/domain/organism/virus.h
        src/domain/simulation/entitytype.h
        src/domain/simulation/simulation.h
        src/domain/space/bodynotinspaceexception.h
        src/domain/space/coordinates.h
        src/domain/space/direction.h
        src/domain/space/space.h
        src/domain/space/vicinity.h
        src/domain/space/vicinityprovider.h src/presentation/presenter/SpaceGridPresenter.h src/presentation/presenter/SpaceGridPresenter.cpp src/presentation/state/ApplicationState.h src/presentation/state/ApplicationEvent.h src/presentation/state/ApplicationEventListener.h src/presentation/state/ApplicationStore.cpp src/presentation/state/ApplicationStore.h src/presentation/view/SpaceGridView.h src/app/model/SpaceGridModel.cpp src/app/model/SpaceGridModel.h src/app/adapter/SpaceGridPresenterAdapter.h src/app/QtApplication.cpp src/app/QtApplication.h src/presentation/presenter/OrganismsListPresenter.cpp src/presentation/presenter/OrganismsListPresenter.h src/presentation/common/GridUtils.h src/presentation/common/GridUtils.cpp src/app/adapter/OrganismsListPresenterAdapter.h src/app/model/OrganismsListModel.cpp src/app/model/OrganismsListModel.h src/presentation/view/OrganismsListView.h src/presentation/presenter/OrganismPropertiesPresenter.cpp src/presentation/presenter/OrganismPropertiesPresenter.h src/app/adapter/OrganismPropertiesPresenterAdapter.h src/app/model/OrganismPropertiesModel.cpp src/app/model/OrganismPropertiesModel.h src/presentation/view/OrganismPropertiesView.h src/presentation/presenter/AddOrganismPresenter.cpp src/presentation/presenter/AddOrganismPresenter.h src/app/model/AddOrganismBarModel.cpp src/app/model/AddOrganismBarModel.h src/app/adapter/AddOrganismPresenterAdapter.h src/presentation/presenter/SimulationControlsPresenter.cpp src/presentation/presenter/SimulationControlsPresenter.h)

target_include_directories(ekosystem PUBLIC src)

target_compile_definitions(ekosystem
        PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(ekosystem
        PRIVATE Qt5::Core Qt5::Quick)
