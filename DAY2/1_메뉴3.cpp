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




