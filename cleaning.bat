pause
for /R %1 in (*Debug*) do (
    if exist "%1" (
        echo Deleting "%1"
        del /F /Q "%1"
    )
for /R %1 in (*x64*) do (
    if exist "%1" (
        echo Deleting "%1"
        del /F /Q "%1"
    )
pause