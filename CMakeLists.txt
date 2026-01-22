cmake_minimum_required(VERSION 3.21)

project(CryptographyProject LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Prefer config packages (Qt provides config packages)
set(CMAKE_FIND_PACKAGE_PREFER_CONFIG ON)

# Qt: generate qmlls ini (optional)
set(QT_QML_GENERATE_QMLLS_INI ON)

# ---- Qt discovery fallback (only if user didn't set it via presets/env) ----
if (NOT DEFINED Qt6_DIR AND NOT DEFINED CMAKE_PREFIX_PATH)
    set(_qt_cmake_hints "")

    if (WIN32)
        file(GLOB _qt_kits "C:/Qt/*/msvc*")
        foreach(_kit IN LISTS _qt_kits)
            list(APPEND _qt_cmake_hints "${_kit}/lib/cmake")
        endforeach()
    elseif(APPLE)
        # Homebrew Qt common locations
        list(APPEND _qt_cmake_hints
            "/opt/homebrew/opt/qt/lib/cmake"
            "/usr/local/opt/qt/lib/cmake"
        )
    endif()

    find_path(Qt6_DIR
        NAMES Qt6Config.cmake
        PATHS ${_qt_cmake_hints}
        PATH_SUFFIXES Qt6
        NO_DEFAULT_PATH
    )

    if (Qt6_DIR)
        set(Qt6_DIR "${Qt6_DIR}" CACHE PATH "Path to Qt6Config.cmake directory" FORCE)
    endif()
endif()

find_package(Qt6 REQUIRED COMPONENTS Core Gui Qml Quick QuickControls2 Widgets)

qt_policy(SET QTP0001 NEW)
qt_policy(SET QTP0004 NEW)

qt_standard_project_setup()

# Qt automoc/uic/rcc
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

add_executable(CryptographyProject
    src/app.cpp
)

qt_add_qml_module(CryptographyProject
    URI CryptographyProject
    VERSION 1.0
    QML_FILES
        # qml/Main.qml
)

target_link_libraries(CryptographyProject PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Qml
    Qt6::Quick
    Qt6::QuickControls2
    Qt6::Widgets
)

if (APPLE)
    set_target_properties(CryptographyProject PROPERTIES MACOSX_BUNDLE TRUE)
endif()

install(TARGETS CryptographyProject
    BUNDLE DESTINATION .
    RUNTIME DESTINATION .
)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)