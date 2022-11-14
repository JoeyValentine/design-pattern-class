#include <iostream>
#include <vector>

// 9. template method ����
// => ��� Ŭ������ ��� ������ ������ Ư¡�� �����ϴµ�...
// => ������ ���� �帧�ӿ� ���ؾ� �ϴ� �κ��� �����Լ�ȭ �ؼ�
//    ���ϴ� �͸� �Ļ� Ŭ������ ������ �Ҽ� �ִ� ��ȸ�� ����
// => ������ ���� ��ü �帧�� �����ϴ�(draw) �� template method ���
//    �մϴ�.


class Shape
{
	int color;
public:
	virtual ~Shape() {}

	void set_color(int c) { color = c; }
	int  get_color() { return color; }

	// ���뼺�� �������� �и�
	// => ������ ���� �ڵ� �帧���� �ִ�, ���ؾ� �ϴ� 
	//    �ڵ�� �и��Ǿ�� �Ѵ�.
	// => ���ϴ� �ڵ带 ã�Ƽ� ������ �����Լ��� �и��Ѵ�.

protected:
	virtual void draw_imp()
	{
		std::cout << "draw shape" << std::endl; 
	}

public:
	// final : �Ļ� Ŭ������ ������ �Ҽ� ���� �Ҷ� ���
	//         java, C# �� ���ʿ� ǥ��, C++�� ���ʿ� ǥ�� 
	virtual void draw() final
	{
		std::cout << "mutex lock" << std::endl;
		draw_imp();
		std::cout << "mutex unlock" << std::endl;
	}





	virtual Shape* clone()
	{
		Shape* p = new Shape;
		p->color = color;

		return p;
	}

	virtual int get_area() { return -1; }
};





class Rect : public Shape
{
public:
	virtual void draw_imp() override { std::cout << "draw rect" << std::endl; }

	virtual Shape* clone() override
	{
		return new Rect(*this); // ���� �����ڷ� ����. 
	}
};


class Circle : public Shape
{
public:
	virtual void draw_imp() override { std::cout << "draw circle" << std::endl; }

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

			v.push_back(v[k]->clone()); 
		}
	}
}

