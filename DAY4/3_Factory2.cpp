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
// Rect 를 생성하는 방법
// 1. Rect* p1 = new Rect;
// 2. Shape* p2 = Rect::Create();


class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }

	static Shape* Create() { return new Circle; }
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
	// C#, swift 등은 "Rect" 처럼 문자열로 을 가지고
	// 객체를 생성할수 있습니다.
	// => 아주 유용하게 활용가능하지만!!
	// => 메모리에 정보를 보관해야 하므로 오버헤드가 큽니다.

	// C++은 할수 없습니다.
}
int main()
{
	Shape* p1 = Create("Rect");
	Shape* p2 = Create("Triangle");
}

// 방법 3. 자신의 객체를 만들수 static 멤버 함수는 항상 유용하게
//        사용됩니다.
Shape* Create(Shape* (*f)())
{
	Shape* p = f();
	return p;
}
int main()
{
	// 인자로 클래스 이름을 보낼수 없지만
	// 클래스의 객체를 생성하는 함수는 보낼수 있습니다.
	Shape* p1 = Create(&Rect::Create);
	Shape* p2 = Create(&Circle::Create);
}


