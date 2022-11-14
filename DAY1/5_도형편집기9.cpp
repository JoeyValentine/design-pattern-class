#include <iostream>
#include <vector>

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

	virtual Rect* clone() override
	{
		return new Rect(*this);
	}
};

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

		// �����غ� ����
		// 1. ��ü�� ���������� �������� ����Ҽ� ������ ?
		//    => ���ο� ������ �߰��Ǿ ���� �ڵ�� ��ȭ���� �ʰ�
		//    => "�߻� ���丮 ����"�� Ȱ���ϸ� �˴ϴ� - ����ϳ� ���ϴ�.

		// 2. Undo/Redo ����� �߰��Ϸ��� ��� �ؾ� �ұ� ?
		//    => "Command" ������ �˸� �˴ϴ�. - ����ϳ� ���ϴ�.

		if      (cmd == 1) { v.push_back(new Rect);}
		else if (cmd == 2) { v.push_back(new Circle);}
		else if (cmd == 9)
		{
			for (auto p : v) p->draw(); // ������ !
		}
		else if (cmd == 8)
		{
			int k = -1;
			std::cout << "���°�� �����ұ�� >> ";
			std::cin >> k;

			v.push_back(v[k]->clone()); // ������ !
		}
	}
}

