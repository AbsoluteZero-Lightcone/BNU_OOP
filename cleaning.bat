rmdir /s /q .vs
for /d /r %%i in (Debug) do (
    rmdir /s /q "%%i"
)
for /d /r %%i in (x64) do (
    rmdir /s /q "%%i"
)