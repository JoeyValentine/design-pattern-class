#include <iostream>
#include <vector>

// 1. ��� ������ Ÿ������ �����ϸ� ���ϴ�.

// 2. ��� ������ ���Ŭ����(Shape) �� �ִٸ� 
//    ��� ������ �Ѱ��� �����̳�(�÷���)�� �����Ҽ� �ִ�.

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
//	std::vector<Rect*>	v; // Rect �� ����
	std::vector<Shape*> v; // ��� ������ ����!!!
}

