// Decorator - 65 page
#include <iostream>

class SpaceShip // 우주 비행선
{
public:
	void Fire()	{ std::cout << "Fire Missile" << std::endl; }
};

// 상속을 사용한 기능의 추가
// => 객체가 아닌 클래스에 기능을 추가한것!
class LeftMissile : public SpaceShip
{
public:
	void Fire()
	{
		SpaceShip::Fire(); // 기존의 기능을 그대로 사용
		std::cout << "Fire Left Missile" << std::endl;
	}
};
int main()
{
	SpaceShip ss;
	ss.Fire();

	LeftMissile lm; // 기존에 존재하던 객체인 ss 에 기능을 추가한것이 
					// 아니라, 기능이 추가된 새로운 객체를 만든것
	lm.Fire();
}