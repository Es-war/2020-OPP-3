@echo off
cd C:/Users/Es war/C
set /p a=请输入所要测试单元
gcc "%a%" -o try.exe
echo 开始测试
try.exe
echo 测试结束
pause