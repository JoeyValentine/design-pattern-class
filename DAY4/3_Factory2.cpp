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
};

class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }
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
	Shape* p = nullptr;

	return p;
}

int main()
{
	Shape* p1 = Create("Rect");
	Shape* p2 = Create("Triangle");
}


