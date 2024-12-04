# 小项目集合
1. 视频播放器——VXPlayer
   1. 集成萤石api
2. 时钟集合——Clock
3. 密码保存box——PasswordBox
4. 四象限优先级安排——taskManage
5. 电子书管理——bookManage


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




# 时钟集合——Clock
## 秒表
## 优先级高
1. 按钮
   1. 批量下载
   2. 当前时间
   3. 双击图标
      1. 弹出快捷键说明
      2. 并可以修改快捷键
2. 计次
   1. 添加最快、最慢显示
   2. 添加备注信息
3. 添加快捷键
   1. 需要考虑光标焦点问题
4. 最新的时间会动态显示
5. 对于大量秒表情况下，添加滚动条
6. 双击删除记录条数
7. 使用spdlog日志
   1. 添加日志类
   2. 程序中改装使用spdlog

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



./getCodeNum.sh 4-QtTest/1-Project/4-XVPlayer/

# 参考资料
[QT开发（五）—— 项目实战：秒表，QTime,Qtimer的使用](https://blog.csdn.net/qq_26787115/article/details/79960628)
# StopClock参考项目
[在线秒表计时器](https://www.lddgo.net/common/stopwatch)
[时钟网](https://clockcn.com/miaobiao/#enabled=0&msec=13768&laps=1436.5120.6459)
[天气网万年历](https://m.wannianli.tianqi.com/jisuanqi/miaobiao/)
[在线秒表 - Online Alarm Kur](https://onlinealarmkur.com/stopwatch/zh-cn/)
微软秒表

