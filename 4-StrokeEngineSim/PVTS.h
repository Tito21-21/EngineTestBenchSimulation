

const double PI = 4 * atan(1.0);

class PVTS {

	const double k = 1.4;

public:

	static int count;
	double r; // compression ratio
	double T1, T2, T3, T4, P1, P2, P3, P4, V1, V2, V3, V4, S1, S2;


	PVTS();
	~PVTS();

	void draw_PV();
	void draw_TS();
	void draw_Inputnum();
	void PVTSinput();
};
