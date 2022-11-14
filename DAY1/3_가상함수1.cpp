#include <iostream>

// 핵심 1. 함수 override

class Animal
{
public:
	// 함수 호출을 컴파일 시간에 결정해 달라
	void cry1() { std::cout << "Animal Cry1" << std::endl; } 

	// virtual function : 함수 호출을 실행 시간에 결정해 달라
	virtual void cry2() { std::cout << "Animal Cry2" << std::endl; }
};
class Dog : public Animal
{
public:
	void cry1() { std::cout << "Dog Cry1" << std::endl; } 

	virtual void cry2() { std::cout << "Dog Cry2" << std::endl; }
};


int main()
{
	Dog d;
	Animal* p = &d; 

	// C++, C#				       : Animal Cry1
	// java, python, swift, kotlin : Dog Cry1

	// 어느 함수를 호출할지를 언제 결정할것인가에 따라 달라집니다.
	// 1. 컴파일 시간에 결정		 : 빠르다
	//							   원리 : 무조건 포인터 타입으로만 결정
	//									 Animal Cry1()
	// 2. 실행할때 메모리 조사후 결정 : 느리다. 
	//								원리 : p가 가리키는 객체를 조사후 호출
	//									  Dog Cry1() 호출
		
	p->cry1(); // Animal Cry1
	p->cry2(); // Dog    Cry2
}


