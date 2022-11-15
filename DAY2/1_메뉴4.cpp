#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 



// ��� �޴��� ������ ��� Ŭ����
class BaseMenu
{	
	std::string title;
public:
	BaseMenu(const std::string& title) : title(title) {}

	virtual ~BaseMenu() {}

	std::string get_title() { return title; }

	// ��� �޴��� ���õɼ� �ִ�.
	// ��� Ŭ�������� "command()" �� �ʿ��ϴ�.
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

			v[cmd - 1]->command(); // v[cmd-1] �� � ������
								// �޴����� ������ �ʿ� ����.
								// "������"
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




