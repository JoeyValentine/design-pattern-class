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
			// 사각형 객체 생성
			Rect* p = new Rect;
			v.push_back(p);
		}
		else if (cmd == 2)
		{
			v.push_back( new Circle );
		}
		else if (cmd == 9)
		{
			for (auto p : v)
				p->draw();
		}
	}
}
// 위 코드는 왜?? 에러일까요 ?
// 해결책은 뭘까요 ??
// 1.
// 2. 
