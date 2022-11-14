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
	// �ٽ� 1. ��� Ŭ������ People �� ����Ʈ �����ڰ� �����ϴ�.
	// => �Ʒ�ó�� �ϸ� �����Ϸ��� "People()" �� ȣ���ϴ� �ڵ带 �����մϴ�.
//	Student(int n) : id(n) {} // Student(int n) : People(), id(n) {} 

	// �ٽ� 2. ��� Ŭ������ �����ڸ� ��������� ȣ���ؾ� �մϴ�.
	Student(const std::string& name, int age, int n) 
		: People(name, age), id(n) {}
};

int main()
{
	// Student ��ü ������ ������.. 
	Student s("kim", 30, 15); // ok
}

// �ʱ�ȭ ����Ʈ ����
class Student : public People
{
	��� ����Ÿ n;
public:
	// �ڵ� ���� �����ؼ�, ������ ��� Ŭ���� �����ڰ� ���� ����˴ϴ�.
//	Student() : ���Ŭ����������(), ��� ����Ÿ �ʱ�ȭ() {}
//	Student() : ��� ����Ÿ �ʱ�ȭ(),  ���Ŭ����������()  {}
				// => �̷��� �ص� ��� Ŭ���� ����!
};
