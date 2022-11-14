#include <iostream>
#include <vector>

// 5. 다형성 : 동일한 표현식이 상황(객체의 종류)에 따라 다르게 동작
// => 새로운 도형이 추가되어도 "다형성 기반의 코드는 변경되지 않는다"!
// => OCP 를 만족하는 아주 좋은 코딩 스타일!!
// => 항상 다형성을 활용해야 한다!!


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
				p->draw();	// 핵심!
					// => 동일한 표현식이 상황(객체의 종류)에 따라 
					//	  다르게 동작 (다른함수 호출)
					// => 다형성(Polymorphism)

			// 객체지향 언어의 3대 특징 : 캡슐화, 상속, 다형성
		}
	}
}

