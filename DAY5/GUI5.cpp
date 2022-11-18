// GUI1
#define USING_GUI
#include "cppmaster.h"
#include <vector>
#include <map>

class Window
{
	int handle;
	static std::map<int, Window*> this_map;

	std::vector<Window*> child_vector;	// 자식 윈도우는 여러개!
	Window* parent = nullptr;	// 부모 윈도우는 한개

public:
	void AddChild(Window* child)
	{
		child_vector.push_back(child);

		child->parent = this;

		// C 함수로 실제 자식 윈도우부착
		ec_add_child(this->handle, child->handle);
	}





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
		case WM_LBUTTONDOWN: self->HandleLButtonDown(); break;
		case WM_KEYDOWN:     self->OnKeyDown(); break;
		}
		return 0;
	}
	
	// 아래 함수가 책임의 전가 패턴의 핵심 구현 입니다.
	void HandleLButtonDown()
	{
		// 1. 자신이 먼저 이벤트 처리(가상함수 호출
		if (OnLButtonDown() == true)
			return;

		// 2. 처리 되지 않은 경우 "부모 윈도우가 있다면 전달" 합니다.
		if (parent != nullptr)
			parent->HandleLButtonDown();
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
		return true;
	}
};

class ImageView : public Window
{
public:
	virtual bool OnLButtonDown()
	{
		std::cout << "ImageView LBUTTONDOWN" << std::endl;
		// return true;	// 이벤트 처리 종료해 달라!
		return false;   // 부모 윈도우에도 전달해 달라.
	}
};






int main()
{
	MainWindow w;
	w.Create();

	ImageView view;
	view.Create();

	w.AddChild(&view);


	ec_process_message();
}

