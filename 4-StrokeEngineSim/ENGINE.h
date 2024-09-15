#include<time.h>
class ENGINE {



public:

	char* p_buffer;
	int N_buffer;
	int Cylinder, Piston, EXValve, INValve, Fire;
	double RPM, ypiston;
	double w;
	float real_t = time(NULL) % 60;
	ENGINE(char* Cylinderpng, char* Pistonpng, char* Valvepng, char* Firepng, char* Sound);
	~ENGINE();

	void draw_Cylinder();
	void draw_Piston();
	void draw_EXValve();
	void draw_INValve();
	void draw_Fire();
	void sound();
	void move_ypiston();
	void Input_RPM();
	void draw_RPMnum();
	void w_time();
};

