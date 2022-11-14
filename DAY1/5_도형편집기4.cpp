#include <iostream>
#include <vector>

// 5. ������ : ������ ǥ������ ��Ȳ(��ü�� ����)�� ���� �ٸ��� ����
// => ���ο� ������ �߰��Ǿ "������ ����� �ڵ�� ������� �ʴ´�"!
// => OCP �� �����ϴ� ���� ���� �ڵ� ��Ÿ��!!
// => �׻� �������� Ȱ���ؾ� �Ѵ�!!


class Shape
{
	int color;
public:
	virtual ~Shape() {}

	void set_color(int c) { color = c; }
	int  get_color() { return c; }

	virtual int get_area() { return -1; }


	virtual void draw() { std::cout << "draw shape" << std::endl; }
};


class Rect : public Shape
{
public:
	virtual void draw() override { std::cout << "draw rect" << std::endl; }
};

class Circle : public Shape
{
public:
	virtual void draw() override { std::cout << "draw circle" << std::endl; }
};

class Triangle : public Shape
{
public:
	virtual void draw() override { std::cout << "draw triangle" << std::endl; }
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
				p->draw();	// �ٽ�!
					// => ������ ǥ������ ��Ȳ(��ü�� ����)�� ���� 
					//	  �ٸ��� ���� (�ٸ��Լ� ȣ��)
					// => ������(Polymorphism)

			// ��ü���� ����� 3�� Ư¡ : ĸ��ȭ, ���, ������
		}
	}
}

