@echo off
setlocal enableExtensions enableDelayedExpansion
set br=^


rem br;
cd /d "%~dp0"		&rem Working/{temp files} Directory . pat>->paf ;


for /f usebackq^ tokens^=*^ delims^=^ eol^= %%f in (`dir /b /a /s "%~1"`) do (
	echo(%%f
	if "%%~xf"==".cpp" (
		rem pushd P:\
		CfgConvert.exe -bin -dst "%%~dpnf.bin" "%%~f"
		if Errorlevel 1 (
			pause
		) else (
			rem del /q "%%~f"
		)
		rem popd
	)
)


:sc_n
rem endlocal
pause
rem exit /b