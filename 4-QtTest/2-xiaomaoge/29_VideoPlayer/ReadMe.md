
//consola 字体
播放器
选择文件
自定义组件
滑动条处理
类的组织
Videoplayer : 预处理视频数据 (解析文件、解码视频流\音频流）
Videowidget : 显示 (渲染) 视频数据
互斥锁、条件变量


Qt Creator中添加ffmpeg，注意win32和win64区分，qt只提供了mingw32编译器，一定要用32位的

使用版本ffmpeg-n6.0-latest-win32-lgpl-shared-6.0

https://www.cnblogs.com/mjios/category/1938094.html?page=2

如果需要加载SDL，需要使用i686-w64-mingw32中的内容，将lib复制到静态库中，lib复制到生成的可执行文件夹中
