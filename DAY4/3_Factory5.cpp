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

// �Ʒ� Ŭ������ ���忡 ��ǰ(����)�� �ڵ����� ����ϱ� ���� Ŭ���� �Դϴ�.
class AutoRegister
{
public:
	AutoRegister(int key, Shape* (*f)())
	{
		ShapeFactory::getInstance().Register(key, f);
	}
};


// ��� ������ ���Ѿ� �ϴ� ��Ģ �ڵ带 �����ϴ� ��ũ�� ����
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




