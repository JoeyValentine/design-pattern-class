// 3_Factory6  - 3���� ���� �ϼ���

#include <iostream>
#include <vector>
#include <map>
#include "Helper.h"

class Shape
{
public:
	virtual void draw() = 0;
	virtual ~Shape() {}

	virtual Shape* clone() = 0;
};

class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }

	virtual Rect* clone() override { return new Rect(*this); }


	static Shape* Create() { return new Rect; }
};


class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }

	virtual Circle* clone() override { return new Circle(*this); }

	static Shape* Create() { return new Circle; }
};




class ShapeFactory
{
	MAKE_SINGLETON(ShapeFactory)

	std::map<int, Shape*> prototype_map;

public:
	void Register(int key, Shape* prototype)
	{
		prototype_map[key] = prototype;
	}

	Shape* Create(int key)
	{
		Shape* p = nullptr;

		if (prototype_map[key] != nullptr)
			p = prototype_map[key]->clone();

		return p;
	}
};



int main()
{
	std::vector<Shape*> v;

	ShapeFactory& factory = ShapeFactory::getInstance();


	// ���忡 ��� ��ǰ�� ����մϴ�.
	// => ���忡 "Ŭ����" ���
//	factory.Register(1, &Rect::Create);
//	factory.Register(2, &Circle::Create);

	// ���忡 Ŭ������ �ƴ� ���� ����ϴ� "��ü" �� ����� ���ô�.
	Rect* redRect = new Rect;
	Rect* blueRect = new Rect;
	Circle* blueCircle = new Circle;

	// ���忡 �ߺ�ǰ(prototype)�� ���
	factory.Register(1, redRect);
	factory.Register(2, blueRect);
	factory.Register(3, blueCircle);




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




