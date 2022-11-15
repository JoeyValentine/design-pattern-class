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
			std::cout << sz + 1 << ". 종료" << std::endl;

			std::cout << "메뉴를 선택하세요 >> ";

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
// 방법 1. 변하는 것을 가상함수로!!! - template method 활용

class MenuItem : public BaseMenu
{
	int id;
public:
	MenuItem(const std::string& title, int id) : BaseMenu(title), id(id) {}

	virtual void command() override
	{
		// 메뉴 아이템 선택시 "공통으로 해야할 작업이 있다면"
		// 여기서 먼저 수행하고.

		// 각 메뉴 마다 다른 작업을 수행하기 위해 다시 가상함수 호출
		do_command();
	}
	virtual void do_command() {}
};
//============================
// 각각의 메뉴를 파생 클래스를 만들어서 사용
class HDMenu : public MenuItem
{
public:
	virtual void do_command() override
	{
		std::cout << "HD 로 해상도 변경" << std::endl;
	}
};

class FHDMenu : public MenuItem
{
public:
	virtual void do_command() override
	{
		std::cout << "FHD 로 해상도 변경" << std::endl;
	}
};
class UHDMenu : public MenuItem
{
public:
	virtual void do_command() override
	{
		std::cout << "UHD 로 해상도 변경" << std::endl;
	}
};

int main()
{
	PopupMenu* root = new PopupMenu("ROOT");

	root->add_menu(new HDMenu("HD", 11));
	root->add_menu(new FHDMenu("FHD", 12));
	root->add_menu(new UHDMenu("UHD", 13));

	root->command();
}




