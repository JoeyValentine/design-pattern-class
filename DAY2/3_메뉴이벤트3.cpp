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
// 방법 2. 변하는 것을 다른 클래스로!!
// => 메뉴 이벤트 처리를 다른 클래스에 위임
// => "리스너" 라는 이름을 가진 이벤트 처리 기술
// => java, 안드로이드 앱, 삼성 타이젠, IOS 의 타겟액션 패턴 기술!!
// 
// => 메뉴 이벤트 처리를 위해 "객체"를 등록하는 하는 패턴!! <=== 핵심 !!!




// 규칙 : 메뉴 이벤트를 처리하고 싶은 클래스는 반드시 아래 인터페이스를
//       구현해야 한다.
struct IMenuListener
{
	virtual void do_command(int id) = 0;
	virtual ~IMenuListener() {}
};


class MenuItem : public BaseMenu
{
	int id;

//	IMenuListener* plistener = nullptr;
	std::vector<IMenuListener*> v;
public:
//	void set_listener(IMenuListener* p) { plistener = p; }
	void add_listener(IMenuListener* p) { v.push_back(p); }

	MenuItem(const std::string& title, int id, 
			IMenuListener* p = nullptr ) : BaseMenu(title), id(id) 
	{
		if (p != nullptr)
			v.push_back(p);
	}

	virtual void command() override
	{
//		if (plistener != nullptr) plistener->do_command();

		for (auto p : v)
			p->do_command(id);
	}
};
//=============================
class Camera : public IMenuListener
{
public:
	void start()
	{
		// 카메라가 사용하는 메뉴 구축
		PopupMenu* root = new PopupMenu("ROOT");
		root->add_menu(new MenuItem("HD", 11, this));
		root->add_menu(new MenuItem("FHD", 12, this));
		root->add_menu(new MenuItem("UHD", 13, this));

		root->command();
	}
	// 메뉴를 처리하기위해 약속된 함수를 만듭니다.
	virtual void do_command(int id) override
	{
		switch (id)
		{
		case 11: std::cout << "Camera HD" << std::endl; break;
		case 12: std::cout << "Camera FHD" << std::endl; break;
		case 13: std::cout << "Camera UHD" << std::endl; break;
		}
		_getch();
	}
};

int main()
{
	Camera cam;
	cam.start();

}




