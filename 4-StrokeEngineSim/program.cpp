
#include <iostream>
#include <cstdio>
#include <cmath>
#include <fstream>
#include <Windows.h> // also needed for the 2D graphics library
#include "2D_graphics.h" // use the 2D graphics library
#include "timer.h" // use the time / clock reading function
#include "game_pad.h"
#include "INTER.h"
#include "ENGINE.h"
#include "PVTS.h"
// for Playsound 
#include <MMSystem.h>
#pragma comment(lib,"winmm.lib") // links a windows library

using namespace std;



int main()
{
	
	initialize_graphics();

	PVTS PV;
	INTER IT ("PVaxis.png", "TSaxis.png", "InputPanel.png", "Background.png");
	ENGINE EN("Cylinder.png", "Piston.png", "Valve.png", "Fire.png", "explosion.wav");

	cout << "\nThe following keys work as follows:\n";
	cout << "\n'R': increases the compression ratio r\n'F': decreases the compression ratio r";
	cout << "\n'T': increases the intake temperature T1\n'G': decreases the intake temperature T1";
	cout << "\n'W': increases the RPM\n'S': decreases the RPM";
	cout << "\n'Q': Exit/Stop Simulation";
	cout << "\nPress 'ENTER' to start the simulation\n";

	getchar();

	while (1) {
		clear();
		
		IT.draw_Background();
		IT.draw_PVaxis();
		IT.draw_TSaxis();
		IT.draw_InputPanel();

		
		PV.PVTSinput();
		PV.draw_PV();
		PV.draw_TS();
		PV.draw_Inputnum();

		EN.w_time();
		EN.Input_RPM();
		EN.move_ypiston();
		EN.draw_Cylinder();
		EN.draw_Piston();
		EN.draw_EXValve();
		EN.draw_INValve();
		EN.draw_Fire();
		EN.draw_RPMnum(); 
		EN.sound();
		
		update();
//		cout << "\nypiston = " << EN.ypiston;
//		cout << "\nw = " << EN.w;
		if (KEY('Q')) break;
	}
	
	cout << "\ndone.\n";
	
	return 0;
}

