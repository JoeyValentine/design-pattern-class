#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

// 객체지향 프로그래밍 : 모든 것은 객체이다.
//                프로그램이 기본 단위는 "함수" 가 아닌 "클래스"이다

class MenuItem
{
	std::string title;
	int id;
public:
	MenuItem(const std::string& title, int id)
		: title(title), id(id) {}

	std::string get_title() { return title; }

	// 메뉴 선택시 호출되는 함수!
	void command()
	{
		std::cout << get_title() << " 메뉴 선택됨" << std::endl;
		_getch(); // 아무키나 누를때 까지 대기
	}
};
int main()
{
	// 각각의 메뉴 항목을 모두 객체로 취급
	MenuItem m1("김밥", 11);
	MenuItem m2("라면", 12);

	m1.command(); // 메뉴 선택 
}




