#include <iostream>

struct Item
{
	virtual void Fire() = 0;
	virtual ~Item() {}
};
//========================================

class SpaceShip : public Item
{
	// 우주선은 다양한 멤버 데이타가 있습니다.
	int color;
	int speed;
	int fuel;
public:
	void Fire() { std::cout << "Fire Missile" << std::endl; }
};
//=================================
// 우주선에 기능을 추가하는 객체들은 
// 공통의 특징이 있습니다.
// 공통의 특징을 담은 기반 클래스를 설계하면 편리합니다
class IDecorator : public Item
{
	Item* item;
public:
	IDecorator(Item* i) : item(i) {}

	void Fire() { item->Fire(); }
};

class LeftMissile : public IDecorator
{
public:
	LeftMissile(Item* s) : IDecorator(s) {}

	void Fire()
	{
		IDecorator::Fire();
		std::cout << "Fire Left Missile" << std::endl; 
	}
};

class RightMissile : public IDecorator
{
public:
	RightMissile(Item* s) : IDecorator(s) {}

	void Fire()
	{
		IDecorator::Fire();
		std::cout << "Fire Right Missile" << std::endl; 
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