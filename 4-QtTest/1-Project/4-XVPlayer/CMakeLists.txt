cmake_minimum_required(VERSION 3.10)

# 设置项目名称和版本
project(VXPlayer VERSION 1.0.0)

# 指定C++标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 查找Qt5包
find_package(Qt5 COMPONENTS Core Gui Widgets REQUIRED)

# 包含Qt头文件目录
include_directories(${Qt5Core_INCLUDE_DIRS} ${Qt5Gui_INCLUDE_DIRS} ${Qt5Widgets_INCLUDE_DIRS})

# 添加第三方库路径
include_directories(${CMAKE_SOURCE_DIR}/../3rdparty/ffmpeg ${CMAKE_SOURCE_DIR}/../3rdparty)

# 设置FFMPEG_HOME变量并添加链接目录
if(WIN32)
    set(FFMPEG_HOME "${CMAKE_SOURCE_DIR}/../lib/ffmpeg") # 没有用
endif()

link_directories(${CMAKE_SOURCE_DIR}/../lib/QMakeAll)
message(WARNING "FFMPEG_HOME ${FFMPEG_HOME}")
# 添加源文件
file(GLOB_RECURSE SOURCES "Clock/*.cpp" "VXPlayer/*.cpp" "MainWindow.cpp" "main.cpp")
file(GLOB_RECURSE HEADERS "Clock/*.h" "VXPlayer/*.h" "Utils.h" "MainWindow.h")

include_directories(.)
include_directories(Clock)

# 添加资源文件（如ui文件）
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

# 确保CMake知道在哪里找到生成的ui头文件
include_directories(${CMAKE_BINARY_DIR})

# 添加可执行文件
add_executable(${PROJECT_NAME} ${SOURCES} ${MOC_SOURCES} ${UI_HEADERS})

# 链接Qt库
target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Core Qt5::Gui Qt5::Widgets)

# 链接外部库
target_link_libraries(${PROJECT_NAME} PRIVATE avcodec avformat avutil SDL2 swresample swscale)

# 添加额外文件到构建系统中
install(FILES README.md DESTINATION .)

# 处理特定于平台的设置
if(WIN32)
    # Windows-specific settings here
endif()

# 如果有其他特定配置，可以继续添加
