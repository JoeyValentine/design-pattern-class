// 3_메뉴이벤트5
#include <iostream>
#include <functional>
using namespace std::placeholders; // _1, _2, _3....

void foo(int a, int b, int c, int d)
{
	printf("%d, %d, %d, %d\n", a, b, c, d);
}
void f1(int a)               { printf("f1\n"); }
void f3(int a, int b, int c) { printf("f3\n"); }

class Dialog
{
public:
	void close(int a, int b) { std::cout << "Camera close" << std::endl; }
};

int main()
{	
	// C의 함수포인터는 유연성이 부족합니다.
//	void(*f)(int) = &f1; //ok
//	f = &f3; // error


	// C++11 의 "std::function" 은 함수 포인터를 일반화한
	// 클래스 템플릿 입니다. - 유연성이 좋습니다.

	std::function<void(int)> f;

	f = &f1;
	f(10); // ok. f1(10);

	//-------------------------------------
//	f = &f3; // error. f3은 인자가 3개 입니다.

	// 핵심 : function 은 bind 결과로 나오는 새로운 함수를 보관할수 있습니다
	
	f = std::bind(&f3, 3, _1, 8);
	f(2); // f3(3, 2, 8);


	// 멤버 함수는 "객체"도 보관해야 합니다.
	Dialog dlg;
	f = std::bind(&Dialog::close, &dlg, 3, _1);
	f(9); // dlg.close(3, 9);


	// 결론 : std::bind 덕분에 std::function 의 객체인 위 f 에는
	//       인자가 한개 이상인 모든 종류의 함수, 멤버 함수, 
	//       static 멤버함수, 람다 표현식등을 전부 보관가능합니다.
}