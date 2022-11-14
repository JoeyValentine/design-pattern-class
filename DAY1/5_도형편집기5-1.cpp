#include <iostream>
#include <vector>

class Shape
{
	int color;
public:
	virtual ~Shape() {}

	void set_color(int c) { color = c; }
	int  get_color() { return color; }

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
				p->draw();
		}

		else if (cmd == 8)
		{
			int k = -1;
			std::cout << "몇번째를 복사할까요 >> ";

			std::cin >> k;

			// 방법 1. k 번째 도형이 어떤 도형인지
			//        dynamic_cast 로 조사하는 방법
			if (dynamic_cast<Rect*>(v[k]) != nullptr )
			{
				// k 번재 도형은 Rect 이다.!!
				v.push_back( new Rect); 
			}
			else if (dynamic_cast<Circle*>(v[k]) != nullptr)
			{
				v.push_back(new Circle);
			}
		}
	}
}

