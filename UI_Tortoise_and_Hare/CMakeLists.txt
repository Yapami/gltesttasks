cmake_minimum_required(VERSION 3.5)

project(TRY_5 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)



# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check http://doc.qt.io/qt-5/deployment-android.html for more information.
# They need to be set before the find_package(Qt5 ...) call.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package(Qt5 COMPONENTS Core Quick REQUIRED)

set(SOURCES main.cpp
    qml.qrc
    ui.cpp
    uitrack.cpp)

qt5_wrap_cpp(SOURCES ui.h)
qt5_wrap_cpp(SOURCES uitrack.h)

 add_executable(TRY_5
  ${SOURCES}
    )


target_compile_definitions(TRY_5
  PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(TRY_5
  PRIVATE Qt5::Core Qt5::Quick rs::track rs::race)

  
project(playground)

find_package(GTest REQUIRED)

include(GoogleTest)

enable_testing()

add_subdirectory("race-simulation")


