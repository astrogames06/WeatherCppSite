FILES=$(find src/ -name "*.cpp")

em++ -o index.js $FILES -std=c++17 -Os -Wall ./lib/libraylib.web.a -I. -I include/ -L. -L lib/ -s USE_GLFW=3 -DPLATFORM_WEB