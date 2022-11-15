#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 



// 모든 메뉴의 공통의 기반 클래스
class BaseMenu
{	
	std::string title;
public:
	BaseMenu(const std::string& title) : title(title) {}

	virtual ~BaseMenu() {}

	std::string get_title() { return title; }

	// 모든 메뉴는 선택될수 있다.
	// 기반 클래스에도 "command()" 가 필요하다.
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
		std::cout << get_title() << " 메뉴 선택됨" << std::endl;
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
			std::cout << sz + 1 << ". 종료" << std::endl;

			std::cout << "메뉴를 선택하세요 >> ";

			int cmd;
			std::cin >> cmd;

			if (cmd == sz + 1)
				break;	

			if (cmd < 1 || cmd > sz + 1) 
				continue; 

			v[cmd - 1]->command(); // v[cmd-1] 이 어떤 종류의
								// 메뉴인자 조사할 필요 없다.
								// "다형성"
		}

	}

};

int main()
{
	MenuItem m1("참치 김밥",   11);
	MenuItem m2("소고기 김밥", 12);
	MenuItem m3("돈까스 김밥", 13);

	MenuItem m4("라면", 20);

	PopupMenu kimbam_pm("김밥류");
	kimbam_pm.add_menu(&m1);
	kimbam_pm.add_menu(&m2);
	kimbam_pm.add_menu(&m3);


	PopupMenu pm("오늘의 메뉴");
	pm.add_menu(&kimbam_pm); // 핵심!!!!
							// popup 은 다시 popup을 보관해야 합니다.
	pm.add_menu(&m4);

	pm.command();  

}




