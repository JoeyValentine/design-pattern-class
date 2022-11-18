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

	// 핵심
	// 멤버 함수        : 인자로 this가 추가됩니다
	// static 멤버 함수 : 인자로 this 추가 안됩니다.
	static int handler(int hwnd, int msg, int a, int b)
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

//Point pt;
//pt.set(10, 20); // set(&pt, 10, 20) 으로 변경되는 것 입니다.