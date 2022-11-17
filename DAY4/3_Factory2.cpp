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
Shape* Create(? arg)
{

}
int main()
{
	Shape* p = Create(? );
}