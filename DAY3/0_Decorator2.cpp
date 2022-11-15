// Decorator - 65 page
#include <iostream>

class SpaceShip // 우주 비행선
{
public:
	void Fire() { std::cout << "Fire Missile" << std::endl; }
};

// 상속을 사용한 기능의 추가 : 객체가 아닌 클래스에 기능을 추가한것!
// 포함을 사용한 기능의 추가
class LeftMissile 
{
	SpaceShip* ship;	// 핵심 : 포인터 또는 참조 타입의 멤버로
public:
	LeftMissile(SpaceShip* s) : ship(s) {}

	void Fire()
	{
		ship->Fire();	// 기존 객체의 기능을 사용하고
		std::cout << "Fire Left Missile" << std::endl; // 새로운 기능을 추가
	}
};

int main()
{
	SpaceShip ss;
	ss.Fire();

	LeftMissile lm(&ss);	// ss 라는 이미 존재 하는 객체에 
							// 새로운 기능을 추가하는 LeftMissile 객체
	lm.Fire();
}