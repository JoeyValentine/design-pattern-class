#include <iostream>
#include <vector>

class Shape
{
public:
	virtual ~Shape() {}
};

class Rect : public Shape
{
public:
	void draw() { std::cout << "draw rect" << std::endl; }
};

class Circle : public Shape
{
public:
	void draw() { std::cout << "draw circle" << std::endl; }
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
			// �簢�� ��ü ����
			Rect* p = new Rect;
			v.push_back(p);
		}
		else if (cmd == 2)
		{
			v.push_back( new Circle );
		}
		else if (cmd == 9)
		{
			for (auto p : v)	// Shape* p �ε�
				p->draw();		// Shape ���� "draw" �Լ��� ����.!
		}
	}
}
// �� �ڵ�� ��?? �����ϱ�� ?
// �ذ�å�� ����� ??
// 1. Shape* �� p �� Rect* �Ǵ� Circle* �� ĳ�����ؼ� �������!
//    => dynamic_cast �� �����Ҽ��� ������ ���� �ʴ�.
// 2. Shape �ȿ� draw �� ����!! => ����!!
