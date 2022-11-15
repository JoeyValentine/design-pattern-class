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
		std::cout << get_title() << " 메뉴 선택됨" << std::endl;
		_getch();
	}
};
int main()
{
	MenuItem m1("김밥", 11);
	MenuItem m2("라면", 12);


	PopupMenu pm("오늘의 메뉴");
	pm.add_menu(&m1);
	pm.add_menu(&m2);

	pm.command();   // 팝업 메뉴를 선택할 때 해야하는 일을 생각해 보세요
					// 
}




