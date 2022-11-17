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

// 방법 1. 아래 처럼 하면 새로운 도형이 추가되면 코드가 수정되어야 합니다.
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

// 방법 2. 클래스 이름을 문자열로 받기
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


