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
		std::cout << get_title() << " �޴� ���õ�" << std::endl;
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

int main()
{
	PopupMenu* root = new PopupMenu("ROOT");
	PopupMenu* pm1 = new PopupMenu("�ػ� ����");
	PopupMenu* pm2 = new PopupMenu("���� ����");

	root->add_menu(pm1);
	root->add_menu(pm2);

	// �Ʒ� ó�� ����ϰ� �ʹٸ�
//	root->get_submenu(0)->add_menu(new MenuItem("HD", 11));

	// ��� 1. get_submenu() �� ��ȯ Ÿ���� PopupMenu �� 
	//        ĳ�����ؼ� �������.
	static_cast<PopupMenu*>(root->get_submenu(0))->add_menu(new MenuItem("HD", 11));

	// ��� 2. BaseMenu �� "get_submenu" �� ��������!!
	// => ���� �������� ����(�޴�7)

	root->command();

}




