// Decorator - 65 page
#include <iostream>

class SpaceShip // ���� ���༱
{
public:
	void Fire() { std::cout << "Fire Missile" << std::endl; }
};

// ����� ����� ����� �߰� : ��ü�� �ƴ� Ŭ������ ����� �߰��Ѱ�!
// ������ ����� ����� �߰�
class LeftMissile 
{
	SpaceShip* ship;	// �ٽ� : ������ �Ǵ� ���� Ÿ���� �����
public:
	LeftMissile(SpaceShip* s) : ship(s) {}


	void Fire()
	{
		SpaceShip::Fire();
		std::cout << "Fire Left Missile" << std::endl;
	}
};

int main()
{
	SpaceShip ss;
	ss.Fire();

	LeftMissile lm; 
	lm.Fire();
}