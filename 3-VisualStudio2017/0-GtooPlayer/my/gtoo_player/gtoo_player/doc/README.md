# 未来需要做的

1. 增加进度条显示，显示当前播放时间
   1. 完善视频信息的结构体，参考potplay播放过程
2. 可以拖动进度条
3. 可以播放声音
4. 播放过程打印信息，显示日志
5. 播放过程显示统计信息
6. 重新更改lib的目录
7. 语言规范


# 比较遥远的目标
1. 学习布局处理


# 如果需要跑起来还需要的东西
1. 3rdparty
   1. ffmpeg
   2. gtest
2. lib的内容

# 优先级较低的
1. 统计代码行数工具-大致完成，只能统计两级目录
2. 测试工具
   1. gtest
      1. 完善测试用例
   2. gcov,lcov
      1. 跨平台使用，可以大致跑通测试覆盖率流程
      2. lcov生成html
3. 跨平台
   1. 使用CMake在ubuntu下编译
   2. qmake在windows平台生成


# 如果需要加入gtest,在编译的时候需要统一生成模式，不然运行时候会报错
```
$(Qt_RUNTIME_) 这是qt原来的生成模式
多线程调试 DLL (/MDd)
```

# gcov
现在，我们将在编译时启用 gcov。使用以下命令编译程序：
```bash
gcc -fprofile-arcs -ftest-coverage -o myprogram main.c functions.c
```
上述命令中：

-fprofile-arcs 启用代码覆盖率的档案生成。
-ftest-coverage 生成与代码行相关的覆盖率信息。
运行生成的可执行文件：

```bash
./myprogram
```
执行完程序后，将会在当前目录下生成一些以 .gcda 和 .gcno 为后缀的文件，这些文件包含了代码覆盖率的信息。

接下来，使用 gcov 分析代码覆盖率。运行以下命令：

```bash
gcov main.c functions.c
```
执行后，会生成一些以 .gcov 为后缀的文件，包含了每个源文件的代码覆盖率信息。

查看生成的 .gcov 文件，你将看到每一行代码的执行次数和覆盖率百分比。

这只是一个简单的例子，实际应用中，你可能会在更大的代码库中使用 gcov，同时可能需要其他工具来处理和可视化代码覆盖率信息。



# lcov

sudo apt-get install lcov

export GCOV_PREFIX="/home/jchen/work/ads/ads_server/server/"
export GCOV_PREFIX_STRIP=4


在代码目录下运行以下命令，以清除之前生成的覆盖率数据和报告：
```bash
lcov --directory . --zerocounters
```
运行你的测试程序。确保它覆盖了你想要测试的代码路径。
```bash
./myprogram
```
收集代码覆盖率数据：
```bash
lcov --directory . --capture --output-file coverage.info
```
生成 HTML 报告：
```bash
genhtml coverage.info --output-directory coverage_report
```
现在，你可以在 coverage_report 目录中找到一个名为 index.html 的文件。打开它，你将看到一个可视化的代码覆盖率报告，其中包含每个源文件的详细信息，覆盖率百分比等。


# 参考资料
[解决gcov不能生成.gcda文件，以及其他错误](https://blog.csdn.net/rheostat/article/details/5983726)
