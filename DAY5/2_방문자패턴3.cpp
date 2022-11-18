#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

// 핵심
// list      : 모든 요소가 동일한 타입을 보관합니다.(list<int> 는 int)
// PopupMenu : 저장하는 요소의 타입이 동일하지 않습니다.
//             (MenuItem, PoupMenu)

class MenuItem;
class PopupMenu;	// 전방선언

struct IMenuVisitor
{
	virtual void visit(MenuItem* mi)  = 0;
	virtual void visit(PopupMenu* pm) = 0;
	virtual ~IMenuVisitor() {}
};








class BaseMenu
{
	std::string title;
public:
	BaseMenu(const std::string& title) : title(title) {}
	virtual ~BaseMenu() {}

	std::string get_title() const { return title; }
	void set_title(const std::string& s) { title = s; }

	virtual void command() = 0;

	// 핵심 : 모든 메뉴는 방문자를 받을수 있어야 한다.
	virtual void Accept(IMenuVisitor* visitor) = 0;
};



class MenuItem : public BaseMenu
{
	int id;
public:
	MenuItem(const std::string& title, int id) : BaseMenu(title), id(id) {}

	void command() override
	{
		std::cout << get_title() << " 메뉴가 선택됨" << std::endl;
		_getch();
	}

	virtual void Accept(IMenuVisitor* visitor) override
	{
		// MenuItem 은 복합객체가 아니므로 자신만 전달하면 됩니다.
		visitor->visit(this);
	}
};




class PopupMenu : public BaseMenu
{
	std::vector<BaseMenu*> v;
public:
	PopupMenu(const std::string& title) : BaseMenu(title) {}

	void add_menu(BaseMenu* p) { v.push_back(p); }

	void command() override
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

			int cmd;
			std::cout << "메뉴를 선택하세요 >> ";
			std::cin >> cmd;

			if (cmd < 1 || cmd > sz + 1)
				continue;

			if (cmd == sz + 1)
				break;

			v[cmd - 1]->command(); 
		}

	}

	virtual void Accept(IMenuVisitor* visitor) override
	{
		// 1. 자신을 방문자에 먼저 보내고
		visitor->visit(this);

		// 2. 자신이 가진 모든 하위 메뉴에 방문자를 방문 시킵니다.
		for (auto p : v)
			p->Accept(visitor);
	}
};

// 메뉴를 방문 하다가 팝업메뉴를 만나면 타이틀을 변경하는 방문자
class PopupMenuTitleChangeVisitor : public IMenuVisitor
{
public:
	virtual void visit(MenuItem* mi) override {}

	virtual void visit(PopupMenu* pm) override 
	{
		std::string title = pm->get_title();

		title = "[ " + title + " ]";

		pm->set_title(title);
	}
};





int main()
{
	PopupMenu* root = new PopupMenu("ROOT");
	PopupMenu* pm1 = new PopupMenu("해상도 변경");
	PopupMenu* pm2 = new PopupMenu("색상 변경");

	root->add_menu(pm1);
	root->add_menu(pm2);

	pm1->add_menu(new MenuItem("HD", 11));
	pm1->add_menu(new MenuItem("FHD", 12));
	pm1->add_menu(new MenuItem("UHD", 13));

	pm2->add_menu(new MenuItem("RED", 21));
	pm2->add_menu(new MenuItem("GREEN", 22));
	pm2->add_menu(new MenuItem("BLUE", 23));

	PopupMenuTitleChangeVisitor pmv;
	root->Accept(&pmv);	// root의 모든 하위 메뉴를
						// 방문해서 popupmenu 의 타이틀을 변경
						// 하는 방문자!

	root->command();

}




