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
        main.cpp
        body/body.cpp
        body/bodyregistry.cpp
        logging/ekolog.cpp
        main.cpp
        organism/human.cpp
        organism/infobundle.cpp
        organism/organism.cpp
        organism/virus.cpp
        simulation/simulation.cpp
        space/space.cpp
        space/vicinity.cpp
        space/vicinityprovider.cpp
        body/body.h
        body/bodyregistry.h
        logging/ekolog.h
        organism/human.h
        organism/infobundle.h
        organism/organism.h
        organism/virus.h
        simulation/entitytype.h
        simulation/simulation.h
        space/bodynotinspaceexception.h
        space/coordinates.h
        space/direction.h
        space/space.h
        space/vicinity.h
        space/vicinityprovider.h)

target_compile_definitions(ekosystem
        PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(ekosystem
        PRIVATE Qt5::Core Qt5::Quick)
