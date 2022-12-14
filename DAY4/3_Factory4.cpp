#include <iostream>
#include <vector>
#include <map>
#include "Helper.h"

class Shape
{
public:
	virtual void draw() = 0;
	virtual ~Shape() {}
};

class ShapeFactory
{
	MAKE_SINGLETON(ShapeFactory)

	typedef Shape* (*CREATOR)();

	std::map<int, CREATOR> create_map;

public:
	void Register(int key, CREATOR f)
	{
		create_map[key] = f;
	}

	Shape* Create(int key)
	{
		Shape* p = nullptr;

		if (create_map[key] != nullptr)
			p = create_map[key]();

		return p;
	}
};

// 아래 클래스는 공장에 제품(도형)을 자동으로 등록하기 위한 클래스 입니다.
class AutoRegister
{
public:
	AutoRegister(int key, Shape* (*f)())
	{
		ShapeFactory::getInstance().Register(key, f);
	}
};

// 전역변수의 생성자는 main 함수 보다 먼저 실행됩니다.
// AutoRegister ar(1, &Rect::Create);








class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }

	static Shape* Create() { return new Rect; }

	// static 멤버 데이타는 결국 전역변수와 유사합니다.
	// Rect 객체를 생성하지 않아도 static 멤버 데이타는 생성됩니다.
	// => ar 의 생성자는 main 이전에 호출된다는 의미
	static AutoRegister ar;
};
AutoRegister Rect::ar(1, &Rect::Create);


// Rect::ar 의 생성자 - 최초에 1회 실행
// new Rect()	=> Rect 생성자 호출
// new Rect()   => Rect 생성자 호출

// C#
/*
class Rect
{
	static Rect() {} // static 생성자, Rect 에 대해서 최초 1회 호출
	Rect() {}		 // instance 생성자, 객체 생성시 마다 호출
};
*/





class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }

	static Shape* Create() { return new Circle; }

	static AutoRegister ar;
};
AutoRegister Circle::ar(2, &Circle::Create);


int main()
{
	std::vector<Shape*> v;

	ShapeFactory& factory = ShapeFactory::getInstance();


	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd >= 1 && cmd <= 7)
		{
			Shape* p = factory.Create(cmd);

			if (p != nullptr)
				v.push_back(p);
		}


		else if (cmd == 9)
		{
			for (int i = 0; i < v.size(); i++)
			{
				v[i]->draw();
			}
		}
	}
}




