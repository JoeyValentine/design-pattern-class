//1_추상클래스2.cpp
#include <iostream>

// OCP
// 기능 확장에는 열려 있고(Open, 모듈/클래스가 추가 되어도)
// 코드 수정에는 닫형 있어야(Close, 기존 코드는 수정되지 않도록)
// 만들어야 한다는 원칙(Principle)

// Open-Close principle
// 개방 폐쇄의 법칙

// 객체지향 설계의 5대 원칙 : SOLID ( SRP, OCP, LSP, ISP, DIP)



class Camera
{
public:	
	void Take() { std::cout << "Take Picture" << std::endl; }
};

class HDCamera
{
public:
	void Take() { std::cout << "Take HD Picture" << std::endl; }
};

class People
{
public:	
	void UseCamera(Camera* p) { p->Take(); }
	void UseCamera(HDCamera* p) { p->Take(); }
};

int main()
{
	People p;
	Camera c;
	p.UseCamera(&c);

	HDCamera hc;
	p.UseCamera(&hc); // ???
}





