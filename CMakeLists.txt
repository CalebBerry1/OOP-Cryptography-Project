cmake_minimum_required(VERSION 3.21)
project(CryptographyProject LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(QT_QML_GENERATE_QMLLS_INI ON)

# Where to find Qt
include(FetchContent)
find_package(Qt6 REQUIRED COMPONENTS Core Gui Qml Quick QuickControls2 Widgets)
qt_standard_project_setup()

qt_policy(SET QTP0001 NEW)
qt_policy(SET QTP0004 NEW)

# Qt Automations
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Prefer config packages
set(CMAKE_FIND_PACKAGE_PREFER_CONFIG ON)

if (NOT DEFINED Qt6_DIR AND NOT DEFINED CMAKE_PREFIX_PATH)
    set(_qt_cmake_hints "")

    if (WIN32)
        file(GLOB _qt_roots "C:/Qt/*/msvc*")
        foreach(_root IN LISTS _qt_roots)
            list(APPEND _qt_cmake_hints "${_root}/lib/cmake")
        endforeach(_root IN LISTS _qt_roots)
    elseif(APPLE)
        list(APPEND _qt_cmake_hints "/opt/homebrew/opt/qt/lib/cmake" "/usr/local/opt/qt/lib/cmake")
    endif()

    find_path(Qt6_DIR 
        NAMES Qt6Config.cmake
        PATHS ${_qt_cmake_hints}
        PATH_SUFFIXES Qt6
        NO_DEFAULT_PATH
    )

    if(Qt6_DIR)
        set(Qt6_DIR "${Qt6_DIR}" CACHE PATH "Path to QtConfig.cmake" FORCE)
    endif()
endif()

# Executable files go here
add_executable()

qt_add_qml_module(
    CryptographyProject
    URI CryptographyProject
    VERSION 1.0
    # Add files using QML here
    QML_FILES
        # i.e. File 1
        # i.e. File 2
)

target_link_libraries(CryptographyProject PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Qml
    Qt6::Quick
    Qt6::QuickControls2
    Qt6::Widgets
)

if(APPLE)
    set_target_properties(CryptographyProject PROPERTIES MACOSX_BUNDLE TRUE)
endif()

target_link_libraries(CryptographyProject PRIVATE Qt6::Core Qt6::Gui Qt6::Qml Qt6::Quick Qt6::QuickControls2 Qt6::Widgets)

install(TARGETS CryptographyProject BUNDLE DESTINATION . RUNTIME DESTINATION .)