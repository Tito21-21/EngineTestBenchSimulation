
#include <iostream>
#include <cstdio>
#include <cmath>
#include <fstream>
#include <Windows.h> // also needed for the 2D graphics library
#include "2D_graphics.h" // use the 2D graphics library
#include "timer.h" // use the time / clock reading function
#include "game_pad.h"
#include "PVTS.h"
// for Playsound 
#include <MMSystem.h>
#pragma comment(lib,"winmm.lib") // links a windows library

using namespace std;




int PVTS::count = 0;

PVTS::PVTS() {

	r = 4.0;

	T1 = 293.0;
	T2 = T1 * (pow(r, (k - 1)));
	T3 = 1591.0;
	T4 = T3 * (pow((1 / r), (k - 1)));

	P1 = 101.3;
	P2 = P1 * (pow(r, k));
	P3 = P2 * T3 / T2;
	P4 = P3 * (pow((1 / r), k));

	V1 = 35.0;
	V2 = V1 / r;
	V3 = V2;
	V4 = V1;

	S1 = V2;
	S2 = 35.0;
	count++;
	cout << "\nPVTS constructed " << " count = " << count << endl;
}

PVTS::~PVTS() {

	count--;
	cout << "\nPVTS destructed " << " count = " << count << endl;
}

void PVTS::draw_PV() {

	const int n = 6;
	double R = 1.0, G = 0.0, B = 0.0;
	double x_scale = 20.0, y_scale = 0.07, x0 = 50, y0 = 100;
	double xl[n], yl[n];

	yl[0] = P1 * y_scale + y0;
	yl[1] = P2 * y_scale + y0;
	yl[2] = P3 * y_scale + y0;
	yl[3] = P4 * y_scale + y0;
	yl[4] = P1 * y_scale + y0;
	yl[5] = P1 * y_scale + y0;

	xl[0] = V1 * x_scale + x0;
	xl[1] = V2 * x_scale + x0;
	xl[2] = V3 * x_scale + x0;
	xl[3] = V4 * x_scale + x0;
	xl[4] = V1 * x_scale + x0;
	xl[5] = V2 * x_scale + x0;

	line(xl, yl, n, R, G, B);

}

void PVTS::draw_TS() {

	const int n = 5;
	double R = 1.0, G = 0.0, B = 0.0;
	double x_scale = 20.0, y_scale = 0.2, x0 = 50, y0 = 600;
	double xl[n], yl[n];

	yl[0] = T1 * y_scale + y0;
	yl[1] = T2 * y_scale + y0;
	yl[2] = T3 * y_scale + y0;
	yl[3] = T4 * y_scale + y0;
	yl[4] = T1 * y_scale + y0;


	xl[0] = S1 * x_scale + x0;
	xl[1] = S1 * x_scale + x0;
	xl[2] = S2 * x_scale + x0;
	xl[3] = S2 * x_scale + x0;
	xl[4] = S1 * x_scale + x0;


	line(xl, yl, n, R, G, B);

}

void PVTS::draw_Inputnum() {
	double scale = 1;
	//text(RPM, 1200, 150, scale);
	text(T1, 1600, 145, scale);
	text(r, 1370, 145, scale);
}


void PVTS::PVTSinput() {
	double t_press, t_ratio = 0.2, t_temp = 0.075;
	static double t_previousr = 0.0, t_previoust = 0.0;


	if (KEY('R') && (r < 10.0)) {

		t_press = high_resolution_time();

		if ((t_press - t_previousr) < t_ratio) return;

		// record it for the next time we enter the function
		t_previousr = t_press;
		r++;
	}

	if (KEY('F') && (r > 4.0)) {

		t_press = high_resolution_time();

		if ((t_press - t_previousr) < t_ratio) return;

		// record it for the next time we enter the function
		t_previousr = t_press;
		r--;
	}

	if (KEY('T') && (T1 < 323.0)) {

		t_press = high_resolution_time();

		if ((t_press - t_previoust) < t_temp) return;

		// record it for the next time we enter the function
		t_previoust = t_press;
		T1++;
	}

	if (KEY('G') && (T1 > 273.0)) {

		t_press = high_resolution_time();

		if ((t_press - t_previoust) < t_temp) return;

		// record it for the next time we enter the function
		t_previoust = t_press;
		T1--;
	}

	T2 = T1 * (pow(r, (k - 1)));
	T4 = T3 * (pow((1 / r), (k - 1)));

	P2 = P1 * (pow(r, k));
	P3 = P2 * T3 / T2;
	P4 = P3 * (pow((1 / r), k));

	V2 = V1 / r;
	V3 = V2;
	V4 = V1;

	S1 = V2;
	S2 = V1;
}
