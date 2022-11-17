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

// ���������� �����ڴ� main �Լ� ���� ���� ����˴ϴ�.
// AutoRegister ar(1, &Rect::Create);








class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }

	static Shape* Create() { return new Rect; }

	// static ��� ����Ÿ�� �ᱹ ���������� �����մϴ�.
	// Rect ��ü�� �������� �ʾƵ� static ��� ����Ÿ�� �����˴ϴ�.
	// => ar �� �����ڴ� main ������ ȣ��ȴٴ� �ǹ�
	static AutoRegister ar;
};
AutoRegister Rect::ar(1, &Rect::Create);


// Rect::ar �� ������ - ���ʿ� 1ȸ ����
// new Rect()	=> Rect ������ ȣ��
// new Rect()   => Rect ������ ȣ��

// C#
/*
class Rect
{
	static Rect() {} // static ������, Rect �� ���ؼ� ���� 1ȸ ȣ��
	Rect() {}		 // instance ������, ��ü ������ ���� ȣ��
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



