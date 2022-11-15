// Decorator - 65 page
#include <iostream>

class SpaceShip // ���� ���༱
{
public:
	void Fire()	{ std::cout << "Fire Missile" << std::endl; }
};

// ����� ����� ����� �߰�
// => ��ü�� �ƴ� Ŭ������ ����� �߰��Ѱ�!
class LeftMissile : public SpaceShip
{
public:
	void Fire()
	{
		SpaceShip::Fire(); // ������ ����� �״�� ���
		std::cout << "Fire Left Missile" << std::endl;
	}
};
int main()
{
	SpaceShip ss;
	ss.Fire();

	LeftMissile lm; // ������ �����ϴ� ��ü�� ss �� ����� �߰��Ѱ��� 
					// �ƴ϶�, ����� �߰��� ���ο� ��ü�� �����
	lm.Fire();
}