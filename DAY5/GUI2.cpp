// GUI1
#define USING_GUI
#include "cppmaster.h"



// 윈도우 클래스를 만들어 봅시다.
class Window
{
	int handle;
public:
	void Create()
	{
		handle = ec_make_window(&handler, "A");
	}

	int handler(int hwnd, int msg, int a, int b)
	{
		switch (msg)
		{
		case WM_LBUTTONDOWN: printf("%x : LBUTTONDOWN\n", hwnd); break;
		case WM_KEYDOWN: printf("%x : KEYDOWN\n", hwnd); break;
		}
		return 0;
	}
};



int main()
{	
	Window w;
	w.Create(); // 윈도우가 생성되어야 합니다.

	ec_process_message();
}