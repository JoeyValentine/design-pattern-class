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
};

class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }

	static Shape* Create() { return new Rect; }
};


class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }

	static Shape* Create() { return new Circle; }
};




class ShapeFactory
{
	MAKE_SINGLETON(ShapeFactory)

		typedef Shape* (*CREATOR)();// �Լ� ������ Ÿ��

	std::map<int, CREATOR> create_map;

public:
	// ���忡 ��ǰ(��Ȯ���� �����Լ�)�� ����ϴ� �Լ�
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



int main()
{
	std::vector<Shape*> v;

	ShapeFactory& factory = ShapeFactory::getInstance();


	// ���忡 ��� ��ǰ�� ����մϴ�.
	factory.Register(1, &Rect::Create);
	factory.Register(2, &Circle::Create);




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




