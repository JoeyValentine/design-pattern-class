#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 


class BaseMenu
{
	std::string title;
public:
	BaseMenu(const std::string& title) : title(title) {}
	virtual ~BaseMenu() {}
	std::string get_title() { return title; }
	virtual void command() = 0;
};

class MenuItem : public BaseMenu
{
	int id;
public:
	MenuItem(const std::string& title, int id)
		: BaseMenu(title), id(id) {}

	virtual void command() override
	{
		std::cout << get_title() << " 메뉴 선택됨" << std::endl;
		_getch();
	}
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

};

int main()
{
	// 아래 코드를 보고 메뉴의 구조를 생각해 보세요
	PopupMenu* root = new PopupMenu("ROOT");
	PopupMenu* pm1 = new PopupMenu("해상도 변경");
	PopupMenu* pm2 = new PopupMenu("색상 변경");

	root->add_menu(pm1);
	root->add_menu(pm2);

	pm1->add_menu(new MenuIem("HD", 11));
	pm1->add_menu(new MenuIem("FHD", 12));
	pm1->add_menu(new MenuIem("UHD", 13));

	pm2->add_menu(new MenuIem("RED",   21));
	pm2->add_menu(new MenuIem("GREEN", 22));
	pm2->add_menu(new MenuIem("BLUE",  23));

	// 이제 시작하려면 어떻게 해야 할까요 ??

}




