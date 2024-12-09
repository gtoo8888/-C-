# 小项目集合
1. 视频播放器——VXPlayer
   1. 集成萤石api
2. 时钟集合——Clock
3. 密码保存box——PasswordBox
4. 四象限优先级安排——taskManage
5. 电子书管理——bookManage
6. 串口助手
7. 背单词


# 视频播放器——VXPlayer
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


上传前都需要格式化

# 时钟集合——Clock
## 秒表
## 优先级高
1. 按钮
   1. 批量下载
2. 设置界面
   1. 修改为点击退出可以确认
   2. 设置
      1. 修改为QQ的滑动确认模式
   3. 添加快捷键
      1. 并可以修改快捷键
      2. ESC，关闭当前窗口
      3. 空格，启动计时，停止计时
      4. crtl+d，下载当前计次信息
      5. 需要考虑光标焦点问题
   4. 秒表显示位数
   5. 关闭主界面，设置界面也关闭
3. 计次
   1. 添加最快、最慢显示
   2. 添加备注信息
4. 最新的时间会动态显示
5. 对于大量秒表情况下，添加滚动条
6. 双击删除记录条数
7. 自动清理
   1. 如果超过一分钟没有操作秒表，自动删除不活跃的秒表
8. 配置统一的头文件
9. qjson替换为cJson


## 优先级中
1. 添加图标  
   1. 主界面图标
   2. clock自己的图标
2. 隐藏到托盘，使用托盘显示
3. 界面相关
   1. StopwatchClockWdg.ui代码实现布局
   2. 主界面随着新秒表的添加扩展长度
   3. 点击秒表界面后，会高亮显示当前选择的秒表
   4. 计次和复位按钮合并？
4. 高级界面
   1. 秒表多了以后，切换显示的形式
      1. 列显示变为格子显示
   2. 改进的秒表管理界面
      1. 统一管理，列表显示
      2. 像是学生管理系统统一管理秒表

## 优先级低
1. 使用clang-format格式化
2. 使用.pro子模块的形式添加代码
3. QTimer是否是新开线程实现？
4. 检测内存占用情况
5. 在线升级

## 测试点
1. 添加测试按钮
2. 运行时间超过一小时，是否会有问题
3. 计次数量达到上限
4. 大规模生成秒表1000个，是否正常运行

## bug

1. 无法正确读取json文件
2. keyshot 拼写错误 keyshort


单独运行程序需要的库
D:\Qt\Qt5.9.9\5.9.9\mingw53_32\bin

libstdc++-6.dll
libwinpthread-1.dll
Qt5Cored.dll
Qt5Guid.dll
Qt5Widgetsd.dll

# CLion的尝试


1. 不要在windows下尝试使用CLion+Qt!!!!!特别是转化已有的工程
2. 将qmake转化为cmake
3. 修改编译器，不然会使用CLion自带的mingw，和qt的mingw有区别


CMakeFiles\VXPlayer.dir/objects.a(ClockWdg.cpp.obj):ClockWdg.cpp:(.text+0x263): undefined reference to `_imp___ZN7QWidgetC2EPS_6QFlagsIN2Qt10WindowTypeEE'
CMakeFiles\VXPlayer.dir/objects.a(ClockWdg.cpp.obj):ClockWdg.cpp:(.text+0x2b5): undefined reference to `_imp___ZN7QWidgetD2Ev'
CMakeFiles\VXPlayer.dir/objects.a(ClockWdg.cpp.obj):ClockWdg.cpp:(.text+0x2fe): undefined reference to `_imp___ZN7QWidgetD2Ev'




./getCodeNum.sh 4-QtTest/1-Project/4-XVPlayer/
./auto_format.sh .


# 参考资料
[QT开发（五）—— 项目实战：秒表，QTime,Qtimer的使用](https://blog.csdn.net/qq_26787115/article/details/79960628)
# StopClock参考项目
[在线秒表计时器](https://www.lddgo.net/common/stopwatch)
[时钟网](https://clockcn.com/miaobiao/#enabled=0&msec=13768&laps=1436.5120.6459)
[天气网万年历](https://m.wannianli.tianqi.com/jisuanqi/miaobiao/)
[在线秒表 - Online Alarm Kur](https://onlinealarmkur.com/stopwatch/zh-cn/)
微软秒表
https://blog.csdn.net/cpp_learner/article/details/118421096
