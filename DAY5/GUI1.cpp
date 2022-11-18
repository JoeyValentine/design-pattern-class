// GUI1
#define USING_GUI
#include "cppmaster.h"

int handler(int hwnd, int msg, int a, int b)
{
	switch (msg)
	{
	case WM_LBUTTONDOWN: printf("%x : LBUTTONDOWN\n", hwnd); break;
	case WM_KEYDOWN: printf("%x : KEYDOWN\n", hwnd); break;
	}
	return 0;
}

int main()
{
	int h1 = ec_make_window(&handler, "A");
	int h2 = ec_make_window(&handler, "B");

	ec_add_child(h1, h2); // h2 �� h1 �� �ڽ�������� �ٿ� �޶�.

	ec_process_message();
}