@echo off

echo ���� python
echo.

curl -o InstallPython.exe "https://mirrors.huaweicloud.com/python/3.11.6/python-3.11.6-amd64.exe"

echo.
echo �������
echo.

echo.
echo ��ʼ��װ python
echo.

InstallPython /quiet PrependPath=1 /passive

echo.
echo ��װ���
echo.

del InstallPython.exe

pause