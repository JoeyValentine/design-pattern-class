#include <iostream>

// ���ּ��� ���ּ��� ����� �߰��ϴ� ��ü(Decorator)�� ������ 
// ��� Ŭ������ �־�� �Ѵ�.
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
		std::cout << "Fire Left Missile" << std::endl; // ���ο� ����� �߰�
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
		std::cout << "Fire Right Missile" << std::endl; // ���ο� ����� �߰�
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