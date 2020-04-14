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
        src/domain/space/vicinityprovider.h)

target_include_directories(ekosystem PUBLIC src)

target_compile_definitions(ekosystem
        PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(ekosystem
        PRIVATE Qt5::Core Qt5::Quick)
