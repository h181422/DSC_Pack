rem @echo %~dp0

set BinPBOPath=B:\Program Files (x86)\Bohemia Interactive\Tools\BinPBO Personal Edition
set ProjectPath=P:
set key=B:\Program Files (x86)\Bohemia Interactive\DUAL.biprivatekey
set ProjectRoot=DSC_Pack.git
set ProjectSrc=DSC_Pack
set ProjectDist=@%ProjectSrc%
set outputDir=B:\Program Files (x86)\Steam\steamapps\common\DayZ\!Workshop
cls

goto cppToBin
pause

:cppToBin
cls
@echo off
setlocal enableExtensions
set br=^
rem br;

cd /d "%ProjectPath%\%projectRoot%\%ProjectSrc%"		&rem Working/{temp files} Directory . pat>->paf ;

for /f usebackq^ tokens^=*^ delims^=^ eol^= %%f in (`dir /b /a /s "%~1"`) do (
	echo(%%f
	if "%%~xf"==".cpp" (
		rem pushd P:\
		cd /d "%ProjectPath%\"
		CfgConvert.exe -bin -dst "%%~dpnf.bin" "%%~f"
		if Errorlevel 1 (
			pause
		) else (
			rem del /q "%%~f"
		)
		rem popd
	)
)
goto makePBO

:makePBO
cd /d "%BinPBOPath%" 
start BinPBO.exe "%ProjectPath%\%ProjectRoot%\%ProjectSrc%" "%ProjectPath%\%ProjectRoot%\%ProjectDist%\Addons" -project "%ProjectPath%\%ProjectRoot%\%ProjectSrc%" -sign "%key%"
FOR /l %%s IN (5,-1,0) DO (
	cls
	echo Compiling, wait %%s seconds
	timeout 1 >nul
)
goto deployPBO

:deployPBO
echo %outputDir%\%ProjectDist%
xcopy "%ProjectPath%\%ProjectRoot%\%ProjectDist%" "%outputDir%\%ProjectDist%\" /e /y /v
pause
