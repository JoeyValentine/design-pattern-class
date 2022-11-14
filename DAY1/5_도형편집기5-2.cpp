#include <iostream>
#include <vector>

class Shape
{
	int color;
public:
	virtual ~Shape() {}

	void set_color(int c) { color = c; }
	int  get_color() { return color; }

	virtual int get_area() { return -1; }


	virtual void draw() { std::cout << "draw shape" << std::endl; }


	// �ڽ��� ���纻�� �����ϴ� �����Լ��� �׻� �����ϰ� ���˴ϴ�.
	virtual Shape* clone()
	{
		Shape* p = new Shape;
		p->color = color; // ��� ����� ���� �ؼ� ������ ��ü��.

		return p;
	}
};





class Rect : public Shape
{
public:
	virtual void draw() override { std::cout << "draw rect" << std::endl; }

	virtual Shape* clone() override 
	{
		return new Rect(*this); // ���� �����ڷ� ����. 
	}
};


class Circle : public Shape
{
public:
	virtual void draw() override { std::cout << "draw circle" << std::endl; }

	virtual Shape* clone() override
	{
		return new Circle(*this); 
	}
};

int main()
{
	std::vector<Shape*> v;

	while (true)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd == 1)
		{
			v.push_back(new Rect);
		}
		else if (cmd == 2)
		{
			v.push_back(new Circle);
		}
		else if (cmd == 9)
		{
			for (auto p : v)
				p->draw();
		}

		else if (cmd == 8)
		{
			int k = -1;
			std::cout << "���°�� �����ұ�� >> ";

			std::cin >> k;

			v.push_back( v[k]->clone() ); // ������!!!
						// => k��° ������ �� �ʿ�(�������ʿ�)����!
						// => ����, ���纻 ����� �޶�� ��û�ϸ�!
						// => ���ο� ������ �߰��Ǿ �� �ڵ��
						//    �������� �ʴ´�.
						//    OCP ����!!
		}
	}
}

