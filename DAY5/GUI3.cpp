// GUI1
#define USING_GUI
#include "cppmaster.h"

class Window
{
	int handle;
public:
	void Create()
	{
		handle = ec_make_window(&handler, "A");
	}

	static int handler(int hwnd, int msg, int a, int b)
	{
		switch (msg)
		{
		case WM_LBUTTONDOWN: OnLButtonDown(); break;
		case WM_KEYDOWN:     OnKeyDown(); break;
		}
		return 0;
	}
	virtual bool OnLButtonDown() { return false; }
	virtual bool OnKeyDown()     { return false; }
};


int main()
{
	Window w;
	w.Create(); 

	ec_process_message();
}

