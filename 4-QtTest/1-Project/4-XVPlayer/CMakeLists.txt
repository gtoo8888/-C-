cmake_minimum_required(VERSION 3.10)
project(VXPlayer VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Core Gui Widgets REQUIRED)

message(WARNING "Qt5Core_LIBRARIES ${Qt5Core_LIBRARIES}")
message(WARNING "Qt5Gui_LIBRARIES ${Qt5Gui_LIBRARIES}")
message(WARNING "Qt5Widgets_LIBRARIES ${Qt5Widgets_LIBRARIES}")

message(WARNING "Qt5Core_LIBRARIES ${Qt5Core_INCLUDE_DIRS}")
message(WARNING "Qt5Gui_LIBRARIES ${Qt5Gui_INCLUDE_DIRS}")
message(WARNING "Qt5Widgets_LIBRARIES ${Qt5Widgets_INCLUDE_DIRS}")

set(CMAKE_PREFIX_PATH "D:\\Qt\\Qt5.9.9\\5.9.9\\mingw53_32\\bin")

include_directories(${Qt5Core_INCLUDE_DIRS} ${Qt5Gui_INCLUDE_DIRS} ${Qt5Widgets_INCLUDE_DIRS})

include_directories(${CMAKE_SOURCE_DIR}/../3rdparty/ffmpeg ${CMAKE_SOURCE_DIR}/../3rdparty)

if(WIN32)
    set(FFMPEG_HOME "${CMAKE_SOURCE_DIR}/../lib/ffmpeg") # 没有用
endif()

link_directories(${CMAKE_SOURCE_DIR}/../lib/QMakeAll)
message(WARNING "FFMPEG_HOME ${FFMPEG_HOME}")

file(GLOB_RECURSE SOURCES "Clock/*.cpp" "VXPlayer/*.cpp" "MainWindow.cpp" "main.cpp")
file(GLOB_RECURSE HEADERS "Clock/*.h" "VXPlayer/*.h" "Utils.h" "MainWindow.h")

include_directories(.)
include_directories(Clock)

set(FORMS
        Clock/ClockWdg.ui
        Clock/StopwatchClockWdg.ui
        Clock/StopwatchWdg.ui
        MainWindow.ui
        XVPlayerWidget.ui
        )

# 使用自动moc处理
qt5_wrap_cpp(MOC_SOURCES ${HEADERS})
qt5_wrap_ui(UI_HEADERS ${FORMS})

include_directories(${CMAKE_BINARY_DIR})
add_executable(${PROJECT_NAME} ${SOURCES} ${MOC_SOURCES} ${UI_HEADERS})

target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Gui Qt5::Widgets)
target_link_libraries(${PROJECT_NAME} avcodec avformat avutil SDL2 swresample swscale)

#install(FILES README.md DESTINATION .)

if(WIN32)
    # Windows-specific settings here
endif()


