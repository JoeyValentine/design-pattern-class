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
	// 핵심 1 : 기반 클래스에 디폴트 생성자가 없으면 아래 2줄은 에러입니다.
//	Derived()     {}  // Derived()      : Base() {}
//	Derived(int a){}  // Derived(int a) : Base(){}

	// 핵심 2 : 기반 클래스에 디폴트 생성자가 없다면
	// => 반드시 파생 클래스를 만들때 기반 클래스의 생성자를 명시적으로
	//    호출해야 합니다.
	Derived()     : Base(0) {}  
	Derived(int a): Base(a) {}
};

int main()
{
	Derived d1;
	Derived d2(5);
}

