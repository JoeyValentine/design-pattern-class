// GUI1
#define USING_GUI
#include "cppmaster.h"



// ������ Ŭ������ ����� ���ô�.
class Window
{
	int handle;
public:
	void Create()
	{
		handle = ec_make_window(&handler, "A");
	}

	// �ٽ�
	// ��� �Լ�        : ���ڷ� this�� �߰��˴ϴ�
	// static ��� �Լ� : ���ڷ� this �߰� �ȵ˴ϴ�.
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
	w.Create(); // �����찡 �����Ǿ�� �մϴ�.

	ec_process_message();
}

//Point pt;
//pt.set(10, 20); // set(&pt, 10, 20) ���� ����Ǵ� �� �Դϴ�.