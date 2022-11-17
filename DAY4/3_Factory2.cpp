#include <iostream>
#include <vector>
#include "Helper.h"

class Shape
{
public:
	virtual void draw() = 0;
	virtual ~Shape() {}
};

class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }

	static Shape* Create() { return new Rect; }
};
// Rect �� �����ϴ� ���
// 1. Rect* p1 = new Rect;
// 2. Shape* p2 = Rect::Create();


class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }

	static Shape* Create() { return new Circle; }
};
//=======================
// �Լ� ���ڿ� ���� �ٸ� ������ ����� �ͽ��ϴ�.
// ��, �̷��� ������� ������ �����ؾ� �մϴ�.

// ��� 1. �Ʒ� ó�� �ϸ� ���ο� ������ �߰��Ǹ� �ڵ尡 �����Ǿ�� �մϴ�.
/*
Shape* Create(int arg)
{
	Shape* p = nullptr;

	switch (arg)
	{
	case 1: p = new Rect; break;
	case 2: p = new Circle; break;
	}
	return p;
}
*/

// ��� 2. Ŭ���� �̸��� ���ڿ��� �ޱ�
Shape* Create( std::string arg)
{
	// C#, swift ���� "Rect" ó�� ���ڿ��� �� ������
	// ��ü�� �����Ҽ� �ֽ��ϴ�.
	// => ���� �����ϰ� Ȱ�밡��������!!
	// => �޸𸮿� ������ �����ؾ� �ϹǷ� ������尡 Ů�ϴ�.

	// C++�� �Ҽ� �����ϴ�.
}
int main()
{
	Shape* p1 = Create("Rect");
	Shape* p2 = Create("Triangle");
}

// ��� 3. �ڽ��� ��ü�� ����� static ��� �Լ��� �׻� �����ϰ�
//        ���˴ϴ�.
Shape* Create(Shape* (*f)())
{
	Shape* p = f();
	return p;
}
int main()
{
	// ���ڷ� Ŭ���� �̸��� ������ ������
	// Ŭ������ ��ü�� �����ϴ� �Լ��� ������ �ֽ��ϴ�.
	Shape* p1 = Create(&Rect::Create);
	Shape* p2 = Create(&Circle::Create);
}


