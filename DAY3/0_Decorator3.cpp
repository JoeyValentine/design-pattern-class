#include <iostream>

// 우주선과 우주선에 기능을 추가하는 객체(Decorator)는 공통의 
// 기반 클래스가 있어야 한다.
struct Item
{
	virtual void Fire() = 0;
	virtual ~Item() {}
};
//========================================


class SpaceShip : public Item
{
public:
	void Fire() { std::cout << "Fire Missile" << std::endl; }
};

class LeftMissile : public Item
{
	Item* ship;
public:
	LeftMissile(Item* s) : ship(s) {}

	void Fire()
	{
		ship->Fire();
		std::cout << "Fire Left Missile" << std::endl; // 새로운 기능을 추가
	}
};

class RightMissile : public Item
{
	Item* ship;
public:
	RightMissile(Item* s) : ship(s) {}

	void Fire()
	{
		ship->Fire();
		std::cout << "Fire Right Missile" << std::endl; // 새로운 기능을 추가
	}
};


int main()
{
	SpaceShip ss;
	ss.Fire();

	LeftMissile lm(&ss);	
	lm.Fire();

	RightMissile rm(&lm);
	rm.Fire();
}