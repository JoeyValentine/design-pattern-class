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
class MenuItem : public BaseMenu
{
	int id;
public:
	MenuItem(const std::string& title, int id) 	: BaseMenu(title), id(id) {}

	virtual void command() override
	{
		// �޴� ������ ���ý� �ؾ��� ���� ���⼭ �����ϸ�
		// ��� �޴��� ������ ���� �ϰ� �˴ϴ�.
		// �޴� �����ۿ� ���� �ٸ� ���� �ؾ� �մϴ�.
	}
};

int main()
{
	PopupMenu* root = new PopupMenu("ROOT");

	root->add_menu(new MenuItem("HD",  11));
	root->add_menu(new MenuItem("FHD", 12));
	root->add_menu(new MenuItem("UHD", 13));

	root->command();
}




