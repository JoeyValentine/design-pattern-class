// 1_생성자1-1.cpp    1번 복사해오세요
#include <iostream>
// 핵심 : 기반 클래스에 디폴트 생성자가 없을때 !!
class Base
{
public:
//	Base() { std::cout << "Base()" << std::endl; }
	Base(int a) { std::cout << "Base(int)" << std::endl; }
	~Base() { std::cout << "~Base()" << std::endl; }
};
class Derived : public Base
{
public:
	Derived() {	}
	Derived(int a){}
};

int main()
{

}

