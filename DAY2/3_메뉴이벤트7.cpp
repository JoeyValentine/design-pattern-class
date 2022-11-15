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
void f0()      { printf("f0\n");         }
void f1(int n) { printf("f1 %d\n", n); }

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
	// 1. 메뉴 이벤트처리 함수의 기본 모양은 "인자가 없는 함수" 입니다.

	// 2. MenuItem 만들때 생성자 3번째 인자로 함수등록 가능합니다.
	// => "f0" 는 인자가 0개 이므로 그냥 주소만 등록하면 됩니다.
	MenuItem* m1 = new MenuItem("HD",  11); 	
	MenuItem* m2 = new MenuItem("FHD", 12, &f0 );

	// 3. add_handler 로 등록해도 됩니다.
	m1->add_handler(&f0);

	// 4. 2개 메뉴에 같은 함수 등록하려면 "인자가 한개인 함수 만들어서"
	//    std::bind 할때 메뉴 ID 고정하세요
	m1->add_handler( std::bind(&f1, 11) ); // ID(11)로 고정
	m2->add_handler( std::bind(&f1, 12) );

	// 5. 람다표현식등 모든 함수 등록 가능합니다.
	m1->add_handler([]() {std::cout << "lambda" << std::endl; });

	// 6. 멤버 함수를 등록할때는 객체 주소도 bind 하세요
	Dialog dlg;
	m1->add_handler(std::bind(&Dialog::close, &dlg, 0, 0));
								// dlg.close(0,0) 호출됨.

	m1->command(); // 등록된 모든 함수 호출됩니다.
}




