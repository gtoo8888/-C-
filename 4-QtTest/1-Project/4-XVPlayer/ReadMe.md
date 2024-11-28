
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

# 现在的问题
可以加载文件，可以音频解码，但是无法播放声音
但是测试后，SDL播放正常的声音是额可以的



# 计时器
# 优先级高
1. 开始启动改为状态机
2. 添加滚动条
3. StopwatchClockWdg.ui代码实现布局

# 优先级中
1. 添加图标  
   1. 主界面图标
   2. clock自己的图标
2. 隐藏到托盘，使用托盘显示

# 优先级低

1. 使用clang-format格式化
2. 使用.pro子模块的形式添加代码


# 参考资料
[QT开发（五）—— 项目实战：秒表，QTime,Qtimer的使用](https://blog.csdn.net/qq_26787115/article/details/79960628)


