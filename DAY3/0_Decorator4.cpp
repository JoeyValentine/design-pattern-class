#include <iostream>

struct Item
{
	virtual void Fire() = 0;
	virtual ~Item() {}
};
//========================================

class SpaceShip : public Item
{
	// ���ּ��� �پ��� ��� ����Ÿ�� �ֽ��ϴ�.
	int color;
	int speed;
	int fuel;
public:
	void Fire() { std::cout << "Fire Missile" << std::endl; }
};
//=================================
// ���ּ��� ����� �߰��ϴ� ��ü���� 
// ������ Ư¡�� �ֽ��ϴ�.
// ������ Ư¡�� ���� ��� Ŭ������ �����ϸ� ���մϴ�
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