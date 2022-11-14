#include <iostream>
#include <vector>

// 3. 모든 파생 클래스(도형)의 공통의 특징은 반드시 기반 클래스(Shape)
//    에도 있어야 한다.
//	  그래야, Shape* 로 모든 도형을 관리할때
//    해당 특징을 사용할수 있다.

// 4. 기반 클래스 멤버 함수중 파생 클래스가 재정의 하게 되는 함수는
//    반드시 "가상함수(virtual)" 로 설계 되어야 한다.!

class Shape
{
	int color;
public:
	virtual ~Shape() {}

	// 아래 2개의 함수는 virtual 로 할까요 ? 하지 말까요 ?
	void set_color(int c) { color = c; }
	int  get_color()      { return c; }

	// 모든 도형은 면적을 구할수 있습니다.
	// virtual 할까요 ? 하지 말까요 ?
	// => 각 도형의 면적을 구하는 방법은 다릅니다.
	// => 각 도형설계자가 구현을 다시 제공해야 합니다.! 
	// => virtual !!
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
	}
}

