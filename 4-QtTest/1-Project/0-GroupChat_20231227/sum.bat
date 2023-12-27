@echo off
setlocal enabledelayedexpansion

rem 设置一个变量total，用于存储总行数
set total=0
rem 遍历当前文件夹中的所有.py文件
for %%f in (*.cpp) do (
    rem 使用findstr命令过滤掉空行，然后使用find命令统计非空行数，并赋值给一个变量count
    for /f %%c in ('findstr /v /r "^$" "%%f" ^| find /c /v ""') do set count=%%c
    rem 打印文件名和非空行数
    echo %%f: !count! lines
    rem 把非空行数累加到总行数上
    set /a total+=count
)
for %%f in (*.h) do (
    rem 使用findstr命令过滤掉空行，然后使用find命令统计非空行数，并赋值给一个变量count
    for /f %%c in ('findstr /v /r "^$" "%%f" ^| find /c /v ""') do set count=%%c
    rem 打印文件名和非空行数
    echo %%f: !count! lines
    rem 把非空行数累加到总行数上
    set /a total+=count
)
rem 打印总行数
echo Total: %total% lines
pause