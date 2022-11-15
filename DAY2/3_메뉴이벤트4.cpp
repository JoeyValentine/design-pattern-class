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
// 방법 3. MenuItem 안에 "객체 주소가 아닌 함수 주소"를 보관
// => 함수 포인터를 사용한 이벤트 처림

class MenuItem : public BaseMenu
{
	int id;
	
	void(*handler)() = nullptr; // 메뉴선택시 호출될 함수 주소를 담을 변수

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
	m.set_handler(&Camera::close); // 멤버 함수 등록???
									// error.
									// 일반 함수 포인터에는 
									// 멤버 함수를 담을수 없다!!
	m.command();	// 메뉴 선택. 
					// 등록된 핸들러 함수(foo) 호출
}




