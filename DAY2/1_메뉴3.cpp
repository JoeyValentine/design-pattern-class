#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

class MenuItem
{
	std::string title;
	int id;
public:
	MenuItem(const std::string& title, int id)
		: title(title), id(id) {}

	std::string get_title() { return title; }

	void command()
	{
		std::cout << get_title() << " �޴� ���õ�" << std::endl;
		_getch();
	}
};


class PopupMenu
{
	std::string title;
	std::vector<MenuItem*> v;
public:
	PopupMenu(const std::string& title) : title(title) {}

	void add_menu(MenuItem* p) { v.push_back(p); }

	// �ٽ� : �˾��޴��� �����Ҷ� ȣ��Ǵ� �Լ�
	void command()
	{
		while (1)
		{
			system("cls"); // ȭ�� �����

			int sz = v.size();
			for (int i = 0; i < sz; i++)
			{
				std::cout << i + 1 << ". " << v[i]->get_title() << std::endl;
			}
			std::cout << sz + 1 << ". ����" << std::endl;

			std::cout << "�޴��� �����ϼ��� >> ";

			int cmd;
			std::cin >> cmd;


			if (cmd == sz + 1) // ���� �޴� ����
				break;	// �Ǵ� return

			if (cmd < 1 || cmd > sz + 1) // �߸��� �Է�
				continue; // �ٽ� �Է� ������ �˴ϴ�.

			v[cmd - 1]->command(); // ���õ� �޴� ����
		}

	}

};

int main()
{
	MenuItem m1("���", 11);
	MenuItem m2("���", 12);

	PopupMenu pm("������ �޴�");
	pm.add_menu(&m1);
	pm.add_menu(&m2);

	pm.command();   // �˾� �޴��� ������ �� �ؾ��ϴ� ���� ������ ������
					// 1. ���
					// 2. ���
					// 3. ����
					// �޴��� �����ϼ��� >> 
}




