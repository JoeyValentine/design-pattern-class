// 1_������2-1.cpp
#include <string>
#include <iostream>

class People
{
	std::string name;
	int age;
public:
	People(const std::string& n, int a) : name(n), age(a)
	{
	}
};
int main()
{
//	People p1;	// �̷��� ��ü�� ����� �ִٴ� ���� ������� ? 
				// (�ʱ�ȭ ���� ���� ��ü)
				// => ���� �ʽ��ϴ�.
				// => �ǵ��� ��� ��ü�� ��ȿ�ϰ�(�����ϼ�)�����Ǿ���մϴ�.

	People p2("kim", 20); // ok.. �ʱ�ȭ�� ��ü
}


