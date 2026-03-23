cmake_minimum_required(VERSION 3.21)

project(CryptographyProject LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_FIND_PACKAGE_PREFER_CONFIG ON)

if (NOT DEFINED Qt6_DIR AND NOT DEFINED CMAKE_PREFIX_PATH)
    set(_qt_cmake_hints "")

    if (WIN32)
        file(GLOB _qt_kits "C:/Qt/*/msvc*")
        foreach(_kit IN LISTS _qt_kits)
            list(APPEND _qt_cmake_hints "${_kit}/lib/cmake")
        endforeach()
    elseif(APPLE)
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

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets Test)

qt_standard_project_setup()

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

qt_add_executable(CryptographyProject
    src/main.cpp
    src/algorithms/XorStreamCipher.h
    src/algorithms/VigenereCipher.h
    src/algorithms/FeistelCipher.h
    src/components/app/mainWindow.h
    src/components/app/mainWindow.cpp
    src/components/pages/homePage.h
    src/components/pages/homePage.cpp
    src/components/pages/encryptPage.h
    src/components/pages/encryptPage.cpp
    src/components/buttons/PrimaryButton.h
    src/components/buttons/PrimaryButton.cpp
    src/components/styles/AppColors.h
    src/components/styles/AppFonts.h
    src/components/styles/AppStyles.h
    src/core/ICipher.h
    src/core/CipherFactory.h
    src/domain/CryptoStep.h
    src/domain/CryptoModels.h
)

target_include_directories(CryptographyProject PRIVATE ${CMAKE_SOURCE_DIR}/src)

target_link_libraries(CryptographyProject PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
    Qt6::Test
)
qt_add_executable(CipherFactoryTest
    test/CipherFactoryTest.cpp
    src/core/CipherFactory.h
    src/core/CipherFactory.cpp
    src/core/ICipher.h
    src/domain/CryptoModels.h
    src/domain/CryptoStep.h
    src/algorithms/XorStreamCipher.h
    src/algorithms/VigenereCipher.h
    src/algorithms/FeistelCipher.h
)

target_link_libraries(CipherFactoryTest PRIVATE
    Qt6::Core
    Qt6::Test
)

target_include_directories(CipherFactoryTest PRIVATE ${CMAKE_SOURCE_DIR}/src)

if (APPLE)
    set_target_properties(CryptographyProject PROPERTIES MACOSX_BUNDLE TRUE)
endif()

install(TARGETS CryptographyProject
    BUNDLE DESTINATION .
    RUNTIME DESTINATION .
)