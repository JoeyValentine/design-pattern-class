#include <iostream>


// 카메라와 카메라 사용자를 먼저 설계하지 말고
// "지켜야 하는 규칙(인터페이스)"를 먼저 설계 하자.



// 인터페이스 : 지켜야 하는 규칙(순수가상함수)만 가진 경우
// 추상클래스 : 규칙 + 다른 멤버도 있는 경우

// C++      : 모두 순수 가상함수 문법을 사용해서 표현
// java, C# : abstract, interface 라는 키워드가 별도로 존재
//==================================================

// 규칙 : "모든 카메라는 아래 클래스로 부터 파생되어야 한다." 라고하지말고
//		 "모든 카메라는 아래 인터페이스를 구현해야 한다" 라고 표현합니다.

// java, C# : class 와 struct 는 값 타입 참조 타입의 커다란 차이지만
// C++ : 단 한가지, 접근지정자 생략시 디폴트가 무엇인가!! 만있습니다.

//class ICamera // 접근지정자 생략시 private 이 디폴트
struct  ICamera // 접근지정자 생략시 public  이 디폴트
{
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

class UHDCamera : public ICamera
{
public:
	void Take() { std::cout << "Take UHD Picture" << std::endl; }
};


int main()
{
	People p;
	Camera c;
	p.UseCamera(&c);

	HDCamera hc;
	p.UseCamera(&hc); // 

	UHDCamera uhc;		// UHDCamera 는 나중에 추가되었지만
	p.UseCamera(&uhc);  // 기존 People 클래스를 수정하지 않고
						// 사용가능하다. - "OCP" 를 만족한다!
}





