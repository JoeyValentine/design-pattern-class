// GUI1
#define USING_GUI
#include "cppmaster.h"
#include <vector>
#include <map>

class Window
{
	int handle;
	static std::map<int, Window*> this_map;

	std::vector<Window*> child_vector;	// �ڽ� ������� ������!
	Window* parent = nullptr;	// �θ� ������� �Ѱ�

public:
	void AddChild(Window* child)
	{
		child_vector.push_back(child);

		child->parent = this;

		// C �Լ��� ���� �ڽ� ���������
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
	
	// �Ʒ� �Լ��� å���� ���� ������ �ٽ� ���� �Դϴ�.
	void HandleLButtonDown()
	{
		// 1. �ڽ��� ���� �̺�Ʈ ó��(�����Լ� ȣ��
		if (OnLButtonDown() == true)
			return;

		// 2. ó�� ���� ���� ��� "�θ� �����찡 �ִٸ� ����" �մϴ�.
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
		// return true;	// �̺�Ʈ ó�� ������ �޶�!
		return false;   // �θ� �����쿡�� ������ �޶�.
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

