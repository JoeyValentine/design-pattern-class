#include <iostream>
#include <vector>

// 1. ��� ������ Ÿ������ �����ϸ� ���ϴ�.


class Rect
{
public:
	void draw() { std::cout << "draw rect" << std::endl; }
};

class Circle
{
public:
	void draw() { std::cout << "draw circle" << std::endl; }
};

int main()
{
	std::vector<Rect*> v; // ?
}

