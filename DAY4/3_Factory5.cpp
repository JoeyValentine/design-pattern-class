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


// 모든 도형이 지켜야 하는 규칙 코드를 생성하는 매크로 제공
#define DECLARE_SHAPE(classname)						\
	static Shape* Create() { return new classname; }	\
	static AutoRegister ar;

#define REGISTER_SHAPE(key, classname)				\
	AutoRegister classname::ar(key, &classname::Create);


class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }

	DECLARE_SHAPE(Rect)
};
REGISTER_SHAPE(1, Rect)


class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }


	DECLARE_SHAPE(Circle)
};
REGISTER_SHAPE(2, Circle)



class Triangle : public Shape
{
public:
	void draw() override { std::cout << "draw Triangle" << std::endl; }


	DECLARE_SHAPE(Triangle)
};
REGISTER_SHAPE(3, Triangle)



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




