:: Needed for looping through src/
setlocal enabledelayedexpansion

set CODE_FILES=
for /R src %%f in (*.cpp) do (
    set "CODE_FILES=!CODE_FILES! %%f"
)
em++ -o index.js %CODE_FILES% -std=c++17 -Os -Wall ./lib/libraylib.web.a -I. -I include/ -L. -L lib/ -s USE_GLFW=3 -DPLATFORM_WEB