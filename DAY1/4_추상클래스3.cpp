#include <iostream>


// 카메라와 카메라 사용자를 먼저 설계하지 말고
// "지켜야 하는 규칙(인터페이스)"를 먼저 설계 하자.

// 규칙 : 모든 카메라는 아래 클래스로 부터 파생되어야 한다.
class ICamera
{
public:
	virtual void Take() = 0;
};

// 아직, 실제 카메라는 없지만 규칙이 있습니다.
// 사용자는 규칙 대로만 사용하면 됩니다.
class People
{
public:
	void UseCamera(ICamera* p) { p->Take(); }
};

// 실제 카메라 제작시에도 "규칙대로 만들면 됩니다."

class Camera : public ICamera
{
public:
	void Take() { std::cout << "Take Picture" << std::endl; }
};

class HDCamera : public ICamera
{
public:
	void Take() { std::cout << "Take HD Picture" << std::endl; }
};

int main()
{
	People p;
	Camera c;
	p.UseCamera(&c);

	HDCamera hc;
	p.UseCamera(&hc); // ???
}





