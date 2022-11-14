#include <iostream>
#include <vector>

// 1. 모든 도형을 타입으로 설계하면 편리하다.

// 2. 모든 도형의 기반클래스(Shape) 가 있다면 
//    모든 도형을 한개의 컨테이너(컬렉션)에 보관할수 있다.

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
//	std::vector<Rect*>	v; // Rect 만 보관
	std::vector<Shape*> v; // 모든 도형을 보관!!!
}

