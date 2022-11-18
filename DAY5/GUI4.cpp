// GUI1
#define USING_GUI
#include "cppmaster.h"
#include <map>

class Window
{
	int handle;
	static std::map<int, Window*> this_map;

public:
	void Create()
	{
		handle = ec_make_window(&handler, "A");

		this_map[handle] = this;
	}

	static int handler(int hwnd, int msg, int a, int b)
	{
		Window* self = this_map[hwnd];

		switch (msg)
		{
		case WM_LBUTTONDOWN: self->OnLButtonDown(); break;
		case WM_KEYDOWN:     self->OnKeyDown(); break;
		}
		return 0;
	}
	virtual bool OnLButtonDown() { return false; }
	virtual bool OnKeyDown() { return false; }
};
std::map<int, Window*> Window::this_map;



class MainWindow : public Window
{
public:
	virtual bool OnLButtonDown()
	{
		std::cout << "MainWindow LBUTTONDOWN" << std::endl;
		return false;
	}
};
int main()
{
	MainWindow w;
	w.Create();

	ec_process_message();
}

