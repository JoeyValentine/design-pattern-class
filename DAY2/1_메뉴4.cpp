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

	void command()
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

};

int main()
{
	MenuItem m1("��ġ ���",   11);
	MenuItem m2("�Ұ�� ���", 12);
	MenuItem m3("��� ���", 13);

	MenuItem m4("���", 20);

	PopupMenu kimbam_pm("����");
	kimbam_pm.add_menu(&m1);
	kimbam_pm.add_menu(&m2);
	kimbam_pm.add_menu(&m3);


	PopupMenu pm("������ �޴�");
	pm.add_menu(&kimbam_pm); // �ٽ�!!!!
							// popup �� �ٽ� popup�� �����ؾ� �մϴ�.
	pm.add_menu(&m4);

	pm.command();  

}




