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
		ship->Fire();	// ���� ��ü�� ����� ����ϰ�
		std::cout << "Fire Left Missile" << std::endl; // ���ο� ����� �߰�
	}
};

int main()
{
	SpaceShip ss;
	ss.Fire();

	LeftMissile lm(&ss);	// ss ��� �̹� ���� �ϴ� ��ü�� 
							// ���ο� ����� �߰��ϴ� LeftMissile ��ü
	lm.Fire();
}