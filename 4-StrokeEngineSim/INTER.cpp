
#include <iostream>
#include <cstdio>
#include <cmath>
#include <fstream>
#include <Windows.h> // also needed for the 2D graphics library
#include "2D_graphics.h" // use the 2D graphics library
#include "timer.h" // use the time / clock reading function
#include "game_pad.h"
#include "INTER.h"
// for Playsound 
#include <MMSystem.h>
#pragma comment(lib,"winmm.lib") // links a windows library

using namespace std;

const double PI = 4 * atan(1.0);



INTER::INTER(char* PV, char* TS, char* Panel, char* Back) {

	create_sprite(PV, PVaxis);
	create_sprite(TS, TSaxis);
	create_sprite(Panel, InputPanel);
	create_sprite(Back, Background);
}

INTER::~INTER() {


}

void INTER::draw_Background() {

	draw_sprite(Background, 0.0, 0.0, 0.0, -1);

}

void INTER::draw_PVaxis() {

	int x_axis = 400, y_axis = 250, theta = 0;
	double scale = 1;

	draw_sprite(PVaxis, x_axis, y_axis, theta, scale);

}

void INTER::draw_TSaxis() {

	int x_axis = 400, y_axis = 750, theta = 0;
	double scale = 1;

	draw_sprite(TSaxis, x_axis, y_axis, theta, scale);
}

void INTER::draw_InputPanel() {

	int x_Panel = 1400, y_Panel = 150, theta = 0;
	double scale = 1;

	draw_sprite(InputPanel, x_Panel, y_Panel, theta, scale);

}
