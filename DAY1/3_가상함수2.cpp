#include <iostream>

// java, C# : "garbage collector" 가 있습니다.
//            언어가 메모리 해지등의 작업을 지원 합니다.
//			  소멸자(finalizer) 를 만들이유가 거의 없습니다.

// C++ : 사용자가 자원관리해야 합니다.
//       소멸자가 아주 중요 합니다.
// 핵심 1. 모든 기반 클래스의 소멸자는 반드시 가상함수로 만들어야 합니다.
//     2. 기반 클래스의 소멸자가 가상함수 라면 모든 파생 클래스의 소멸자도
//        virtual 입니다.(virtual 을 붙이지 않아도)
class Base
{
public:
	virtual ~Base() { std::cout << "~Base" << std::endl; }
};
class Derived : public Base
{
public:
	Derived()  { std::cout << "Derived() 자원할당" << std::endl; }
	~Derived() { std::cout << "~Derived() 자원해지" << std::endl; }
};
class Derived2: public Derived
{
public:
	Derived2() { std::cout << "Derived2() 자원할당" << std::endl; }
	~Derived2() { std::cout << "~Derived2() 자원해지" << std::endl; }
};
int main()
{
//	Derived d;

//	Derived* p = new Derived; // 생성자 호출
//	delete p;  // 이순간 객체가 파괴 되므로 소멸자 호출


	Base* p = new Derived2; // 생성자 호출

	delete p; // 이순간 소멸자를 호출해야 하는데
			  // 컴파일 할때 호출을 결정할지, 실행할때 할지 정해야합니다.
			  // 
			// 1. p가 Base* 타입이므로 Base 클래스를 조사해서
			//    소멸자가 가상함수 인지 조사
			// 가상함수가 아니면 : 무조건 Base 소멸자 호출
			// 가상함수라면     : 실행할때 메모리 조사후 결정
}	




