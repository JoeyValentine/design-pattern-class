#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 


// Menu 예제 핵심 정리

// 복합객체(PopupMenu) 는 개별객체(MenuItem) 뿐 아니라
// 복합객체 자신도 보관할수 있다.
// => 재귀적인 포함 관계
// => 복합객체와 개별객체는 동일한 기반 클래스가 있어야 한다.

// 복합객체와 개별객체는 사용법이 동일하다.
// => 모두 선택되면 command() 호출
// => command() 는 기반 클래스(BaseMenu) 에 있어야 한다.


// 객체의 포함 관계는 "tree 구조"로 구성된다.

// 메뉴 예제 뿐 아니라 다양한 예제에서 
// 위와 같은 구조를 사용

// "Composite 패턴"




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
	// 객체지향 언어에서 프로그램이란 ?
	// => 객체를 생성하고, 
	// => 객체간의 관계를 설정하고, 
	// => 객체간의 메세지를 주고 받는 것이다.(멤버 함수를 호출한다는 의미)

	// 아래 코드를 보고 메뉴의 구조를 생각해 보세요
	PopupMenu* root = new PopupMenu("ROOT");
	PopupMenu* pm1  = new PopupMenu("해상도 변경");
	PopupMenu* pm2  = new PopupMenu("색상 변경");

	root->add_menu(pm1);
	root->add_menu(pm2);
//	pm1->add_menu(pm2);

	pm1->add_menu(new MenuItem("HD", 11));
	pm1->add_menu(new MenuItem("FHD", 12));
	pm1->add_menu(new MenuItem("UHD", 13));
	pm1->add_menu(new MenuItem("8K", 14));

	pm2->add_menu(new MenuItem("RED",   21));
	pm2->add_menu(new MenuItem("GREEN", 22));
	pm2->add_menu(new MenuItem("BLUE",  23));

	// 이제 시작하려면 어떻게 해야 할까요 ??
	root->command();

}




