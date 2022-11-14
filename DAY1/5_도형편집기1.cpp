#include <iostream>
#include <vector>

// 1. 모든 도형을 타입으로 설계하면 편리하다.


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

