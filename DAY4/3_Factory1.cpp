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

// ������ ����� ���丮
// => ���� ������ ���ο� ������ �߰��Ǹ� "ShapeFactory" �� �����Ǿ�� �մϴ�.
// => ������, ������ ������ �Ѱ����� ���� �ǹǷ�
//    ���ο� ���� �߰��� �Ѱ�(ShapeFactory) �� ����Ǹ� �˴ϴ�.
// => ��ȭ�� �ּ�ȭ �Ҽ� �ֽ��ϴ�.

class ShapeFactory
{
	MAKE_SINGLETON(ShapeFactory)
public:
	Shape* Create(int type)
	{
		Shape* p = nullptr;
		if      (type == 1)	p = new Rect;
		else if (type == 2)	p = new Circle;
		return p;
	}
};

int main()
{
	std::vector<Shape*> v;

	ShapeFactory& factory = ShapeFactory::getInstance();

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd >= 1 && cmd <= 7) // 1 ~ 7 �� ������ȣ�� ����
		{
			Shape* p = factory.Create(cmd);

			if (p != nullptr)
				v.push_back(p);
		}


		else if (cmd == 9)
		{
			for (int i = 0; i < v.size(); i++)
			{
				v[i]->draw();	// ������!!!
								// ���ο� ������ �߰��Ǿ �����������
								// OCP ����!
			}					
		}
	}
}



