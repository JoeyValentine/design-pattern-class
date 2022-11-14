#include <iostream>
#include <vector>

// �ڵ� ����

class NotImplemented {};

class Shape
{
	int color;
public:
	virtual ~Shape() {}

	void set_color(int c) { color = c; }
	int  get_color() { return color; }

	virtual void draw() final
	{
		std::cout << "mutex lock" << std::endl;
		draw_imp();
		std::cout << "mutex unlock" << std::endl;
	}
protected:
	virtual void draw_imp() = 0;

public:
	virtual Shape* clone() { throw NotImplemented(); return 0; }

	virtual int get_area() { return -1; }
};





class Rect : public Shape
{
public:
	virtual void draw_imp() override { std::cout << "draw rect" << std::endl; }

	// ���� �Լ��� ��ȯ Ÿ���� "��Ӱ����� Ÿ��"���� ���� �����մϴ�
	// ��κ��� ��ü���� �� ����
	// "���� ��ȯ�� ��Ģ" �̶�� �մϴ�.
	virtual Rect* clone() override
	{
		return new Rect(*this);
	}
};
// Rect* p1 = new Rect;
// Rect* p2 = p1->clone(); // �̷��� �ް� �ʹٸ�
//						  clone �� ��ȯ Ÿ���� Rect* �̾�� �մϴ�.

class Circle : public Shape
{
public:
	virtual void draw_imp() override { std::cout << "draw circle" << std::endl; }

	virtual Circle* clone() override
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

