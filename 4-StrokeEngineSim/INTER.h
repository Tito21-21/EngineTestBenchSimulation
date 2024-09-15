
class INTER {



public:

	int PVaxis, TSaxis, InputPanel, Background;

	INTER(char* PV, char* TS, char* Panel, char* Back);
	~INTER();
	void draw_Background();
	void draw_PVaxis();
	void draw_TSaxis();
	void draw_InputPanel();

};
