
#include <iostream>
#include <cstdio>
#include <cmath>
#include <fstream>
#include <Windows.h> // also needed for the 2D graphics library
#include "2D_graphics.h" // use the 2D graphics library
#include "timer.h" // use the time / clock reading function
#include "game_pad.h"
#include "ENGINE.h"
// for Playsound 
#include <MMSystem.h>
#pragma comment(lib,"winmm.lib") // links a windows library

using namespace std;

const double PI = 4 * atan(1.0);

ENGINE::ENGINE(char* Cylinderpng, char* Pistonpng, char* Valvepng, char* Firepng, char* Sound) {

	RPM = 0.0;
	w = 0.0;
	ypiston = 640;

	create_sprite(Cylinderpng, Cylinder);
	create_sprite(Pistonpng, Piston);
	create_sprite(Valvepng, EXValve);
	create_sprite(Valvepng, INValve);
	create_sprite(Firepng, Fire);

	ifstream fin;

	fin.open(Sound, ios::binary);

	if (!fin) {
		cout << "\nfile open error";
	}

	fin.seekg(0, ios::end); // move to the end of the file

	N_buffer = fin.tellg(); // get the current position -> size of file

	fin.seekg(0, ios::beg); // move to the beginning of the file (rewind)

	cout << "N_buffer = " << N_buffer << endl;

	p_buffer = new char[N_buffer];

	if (p_buffer == NULL) {
		cout << "\nerror allocating the dynamic memory";
	}

	fin.read(p_buffer, N_buffer);

	fin.close();

}

ENGINE::~ENGINE() {

	if (p_buffer != NULL) delete p_buffer;
}



void ENGINE::draw_Cylinder() {

	double x = 1600, y = 660, scale = 1, theta = 0;

	draw_sprite(Cylinder, x, y, theta, scale);

}

void ENGINE::draw_Piston() {

	double x = 1600, scale = 1, theta = 0;

	draw_sprite(Piston, x, ypiston, theta, scale);

}

void ENGINE::draw_EXValve() {

	double x = 1667, y, scale = 1, theta = 0;
	if (((w >= 3.5 * PI) && (w <= 4 * PI)) || (w <= PI / 2)) {
		y = 800;
	}
	else y = 860;

	draw_sprite(EXValve, x, y, theta, scale);
}

void ENGINE::draw_INValve() {

	double x = 1533, y, scale = 1, theta = 0;
	if ((w >= PI / 2) && (w <= 3 * PI / 2)) {
		y = 800;
	}
	else y = 860;
	draw_sprite(INValve, x, y, theta, scale);
}

void ENGINE::draw_Fire() {

	double x = 1600, y = 780, scale = 1, theta = 0;

	if ((w >= 2.5 * PI) && (w <= 3 * PI)) {

		draw_sprite(Fire, x, y, theta, scale);
	}
}

void ENGINE::sound() {

	if ((w >= 2.5 * PI) && (w <= 3 * PI)) {

		PlaySoundA(p_buffer, NULL, SND_MEMORY | SND_ASYNC);
	}
	//	if (p_buffer != NULL) delete p_buffer;
}

void ENGINE::draw_RPMnum() {

	double scale = 1;
	text(RPM, 1070, 145, scale);
}

void ENGINE::Input_RPM() {

	double t_press, v_scale = 0.5;
	static double t_previous = 0.0, t_rpm = 0.0001;
	t_press = high_resolution_time();

	if (KEY('W') && (RPM < 5000.0)) {

		t_press = high_resolution_time();

		if ((t_press - t_previous) < t_rpm) return;

		// record it for the next time we enter the function
		t_previous = t_press;
		RPM++;
	}

	if (KEY('S') && (RPM > 0.0)) {

		t_press = high_resolution_time();

		if ((t_press - t_previous) < t_rpm) return;

		// record it for the next time we enter the function
		t_previous = t_press;
		RPM--;
	}
}

void ENGINE::move_ypiston() {

	double yc = 550;
	ypiston = yc + 110 * sin(w);
}

void ENGINE::w_time() {

	//	double t;

	w += (RPM/65*real_t * 2 * PI / 60) ;
	Sleep(1);
	if (w >= 4 * PI) {
		w = 0.0;
	}
}