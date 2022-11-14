#include <iostream>
// 핵심 : 생성자 호출의 정확한 원리!
class Base
{
public:
	Base() { std::cout << "Base()" << std::endl; }
	Base(int a){ std::cout << "Base(int)" << std::endl; }
	~Base()    { std::cout << "~Base()" << std::endl; }
};
class Derived : public Base
{
public:	
	// 사용자코드			// 컴파일러가 변경한 코드
	Derived()			// Derived() : Base() 
	{ 
		std::cout << "Derived()" << std::endl; 
	}
						// 핵심 : 컴파일러 제공 코드는 항상
						//		 기반 클래스의 디폴트 생성자 호출
	Derived(int a)		// Derived(int a) : Base() 
	{ 
		std::cout << "Derived(int)" << std::endl; 
	}
	~Derived()		
	{
		std::cout << "~Derived()" << std::endl; 

		// 소멸자는 사용자가 만든 코드를 먼저실행하게 하고
		// 컴파일러가 아래 코드 추가
		// ~Base();
	}
};
int main()
{
//	Derived d1;		// call Derived::Derived()
	Derived d2(5);  // call Derived::Derived(5)

}

