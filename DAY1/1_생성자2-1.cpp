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
// People �κ��� ��ӹ��� Student ����� ������
// ��� ����Ÿ�� �й�(id) �߰��� ������
// => �ٽ� : ������ ����� ������
class Student : public People
{
	int id;
public:
	//
};
int main()
{
	// Student ��ü ������ ������.. 
}


