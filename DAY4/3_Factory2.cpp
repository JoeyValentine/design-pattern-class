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
// 함수 인자에 따라 다른 도형을 만들고 싶습니다.
// 단, 미래에 만들어질 도형도 가능해야 합니다.
Shape* Create(? arg)
{

}
int main()
{
	Shape* p = Create(? );
}