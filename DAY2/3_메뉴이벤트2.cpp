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
// ��� 1. ���ϴ� ���� �����Լ���!!! - template method Ȱ��

class MenuItem : public BaseMenu
{
	int id;
public:
	MenuItem(const std::string& title, int id) : BaseMenu(title), id(id) {}

	virtual void command() override
	{
		// �޴� ������ ���ý� "�������� �ؾ��� �۾��� �ִٸ�"
		// ���⼭ ���� �����ϰ�.

		// �� �޴� ���� �ٸ� �۾��� �����ϱ� ���� �ٽ� �����Լ� ȣ��
		do_command();
	}
	virtual void do_command() {}
};
//============================
// ������ �޴��� �Ļ� Ŭ������ ���� ���
class HDMenu : public MenuItem
{
public:
	virtual void do_command() override
	{
		std::cout << "HD �� �ػ� ����" << std::endl;
	}
};

class FHDMenu : public MenuItem
{
public:
	virtual void do_command() override
	{
		std::cout << "FHD �� �ػ� ����" << std::endl;
	}
};
class UHDMenu : public MenuItem
{
public:
	virtual void do_command() override
	{
		std::cout << "UHD �� �ػ� ����" << std::endl;
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




