@echo off
set /p a=请输入文件所在磁盘
cd "%a%"
set /p b=请输入文件所在路径
cd "%b%"
set /p c=请输入文件名
echo 编译开始
gcc "%c%" -o try.exe
if exist "try.exe" echo 编译成功
if not exist "try.exe" echo 编译失败
pause