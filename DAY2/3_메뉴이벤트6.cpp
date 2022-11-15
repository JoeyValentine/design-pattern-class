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

class Camera
{
public:
	void close(int a, int b) { std::cout << "Camera close" << std::endl; }
};

int main()
{	
	// C의 함수포인터는 유연성이 부족합니다.
	void(*f)(int) = &f1; //ok
//	f = &f3; // error

}