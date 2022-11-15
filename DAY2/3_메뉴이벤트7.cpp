#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 
#include <functional> // std::bind, std::function
using namespace std::placeholders;  // _1, _2, _3



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
// 방법 3. 함수 포인터가 아닌 "std::function" 사용

class MenuItem : public BaseMenu
{
	int id;
	using HANDLER = std::function<void()>;

	std::vector< HANDLER > v;
public:
	MenuItem(const std::string& title, int id, HANDLER h = nullptr) 
		: BaseMenu(title), id(id) 
	{
		if (h != nullptr)
			v.push_back(h);
	}
	void add_handler(HANDLER h) { v.push_back(h); }

	virtual void command() override
	{
		for (auto f : v)
			f();
	}
};
//--------------------------------------
void f0()      { printf("f0");         _getch(); }
void f1(int n) { printf("f1 %d\n", n); _getch(); }

class Dialog
{
public:
	void close(int a, int b)
	{
		std::cout << "Dialog close" << std::endl;
	}
};

int main()
{
	PopupMenu* root = new PopupMenu("ROOT");

	MenuItem* m1 = new MenuItem("HD", 11, f0); 
	
	MenuItem* m2 = new MenuItem("FHD", 12);

	root->command();
}




