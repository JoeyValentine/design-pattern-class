#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 


class BadOperation {};


class BaseMenu
{
	std::string title;
public:
	BaseMenu(const std::string& title) : title(title) {}
	virtual ~BaseMenu() {}
	std::string get_title() { return title; }
	virtual void command() = 0;

	virtual void add_menu(BaseMenu*) { throw BadOperation(); }
	virtual void remove_menu(int idx) { throw BadOperation(); }

	virtual BaseMenu* get_submenu(int idx) { throw BadOperation(); }
};





class PopupMenu : public BaseMenu
{
	std::vector<BaseMenu*> v;
public:
	PopupMenu(const std::string& title) : BaseMenu(title) {}

	void add_menu(BaseMenu* p) { v.push_back(p); }

	virtual void command() override
	{
		while (1)
		{
			system("cls");

			int sz = v.size();
			for (int i = 0; i < sz; i++)
			{
				std::cout << i + 1 << ". " << v[i]->get_title() << std::endl;
			}
			std::cout << sz + 1 << ". ����" << std::endl;

			std::cout << "�޴��� �����ϼ��� >> ";

			int cmd;
			std::cin >> cmd;

			if (cmd == sz + 1)
				break;

			if (cmd < 1 || cmd > sz + 1)
				continue;

			v[cmd - 1]->command();
		}

	}

	BaseMenu* get_submenu(int idx) { return v[idx]; }
};

//=================================================
// ��� 3. MenuItem �ȿ� "��ü �ּҰ� �ƴ� �Լ� �ּ�"�� ����
// => �Լ� �����͸� ����� �̺�Ʈ ó��

class MenuItem : public BaseMenu
{
	int id;
	
	void(*handler)() = nullptr; // �޴����ý� ȣ��� �Լ� �ּҸ� ���� ����

public:
	MenuItem(const std::string& title, int id) : BaseMenu(title), id(id) {}

	void set_handler( void(*f)() ) { handler = f; }

	virtual void command() override
	{
		if (handler != nullptr)
			handler();
	}
};
//======================
void foo() { std::cout << "foo" << std::endl; }

class Camera
{
public:
	void close() {}
};

int main()
{
	MenuItem m("HD", 11);
	m.set_handler(&foo);
	m.set_handler(&Camera::close); // ��� �Լ� ���???
									// error.
									// �Ϲ� �Լ� �����Ϳ��� 
									// ��� �Լ��� ������ ����!!
	m.command();	// �޴� ����. 
					// ��ϵ� �ڵ鷯 �Լ�(foo) ȣ��
}




