#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

// ��ü���� ���α׷��� : ��� ���� ��ü�̴�.
//                ���α׷��� �⺻ ������ "�Լ�" �� �ƴ� "Ŭ����"�̴�

class MenuItem
{
	std::string title;
	int id;
public:
	MenuItem(const std::string& title, int id)
		: title(title), id(id) {}

	std::string get_title() { return title; }

	// �޴� ���ý� ȣ��Ǵ� �Լ�!
	void command()
	{
		std::cout << get_title() << " �޴� ���õ�" << std::endl;
		_getch(); // �ƹ�Ű�� ������ ���� ���
	}
};
int main()
{
	// ������ �޴� �׸��� ��� ��ü�� ���
	MenuItem m1("���", 11);
	MenuItem m2("���", 12);

	m1.command(); // �޴� ���� 
}




