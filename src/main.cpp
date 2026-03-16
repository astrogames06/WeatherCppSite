#include <raylib.h>
#include <raymath.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cstdlib>

#define RAYGUI_IMPLEMENTATION
#include <raygui.h>

#define PLATFORM_WEB
#if defined(PLATFORM_WEB)
    #include <emscripten/emscripten.h>
	#include <emscripten/val.h>
	#include <emscripten/bind.h>
#endif


const int WIDTH = 850;
const int HEIGHT = 450;
Color BG_COLOR = Color {0, 149, 194, 255};

std::string area_global = "Loading...";
void set_area(std::string city)
{
	area_global = city;
}

std::string weather_desc = "Loading...";
void set_weather_desc(std::string weather_desc_inp)
{
	weather_desc = weather_desc_inp;
}

std::string temperature = "Loading...";
void set_temperature(std::string temperature_inp)
{
	temperature = temperature_inp;
}

EMSCRIPTEN_BINDINGS(my_module)
{
	emscripten::function("set_area", &set_area);
	emscripten::function("set_weather_desc", &set_weather_desc);
	emscripten::function("set_temperature", &set_temperature);
}

void UpdateDrawFrame();

int main(void)
{
	InitWindow(WIDTH, HEIGHT, "Weather App");

	#if defined(PLATFORM_WEB)
    	emscripten_set_main_loop(UpdateDrawFrame, 0, 1);
	#else
		SetTargetFPS(60);   // Set our game to run at 60 frames-per-second
		//--------------------------------------------------------------------------------------

		// Main game loop
		while (!WindowShouldClose())    // Detect window close button or ESC key
		{
			UpdateDrawFrame();
		}
	#endif

	CloseWindow();

	return 0;
}

void UpdateDrawFrame()
{
	BeginDrawing();
	
	ClearBackground(BG_COLOR);

	std::string city_str = "Area: " + area_global;
	DrawText(city_str.c_str(), 20, 20, 20, BLACK);

	std::string weather_desc_str = "Weather: " + weather_desc;
	DrawText(weather_desc_str.c_str(), 20, 50, 20, BLACK);

	std::string temperature_str = "Temperature: " + temperature + "°C";
	DrawText(temperature_str.c_str(), 20, 80, 20, BLACK);

	EndDrawing();
}