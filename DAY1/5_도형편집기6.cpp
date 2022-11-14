#include <iostream>
#include <vector>

// 9. template method 패턴
// => 기반 클래스가 모든 도형의 공통의 특징을 제공하는데...
// => 변하지 않은 흐름속에 변해야 하는 부분을 가상함수화 해서
//    변하는 것만 파생 클래스가 재정의 할수 있는 기회를 제공
// => 변하지 않은 전체 흐름을 제공하는(draw) 를 template method 라고
//    합니다.


class Shape
{
	int color;
public:
	virtual ~Shape() {}

	void set_color(int c) { color = c; }
	int  get_color() { return color; }

	// 공통성과 가변성의 분리
	// => 변하지 않은 코드 흐름내에 있는, 변해야 하는 
	//    코드는 분리되어야 한다.
	// => 변하는 코드를 찾아서 별도의 가상함수로 분리한다.

protected:
	virtual void draw_imp()
	{
		std::cout << "draw shape" << std::endl; 
	}

public:
	// final : 파생 클래스가 재정의 할수 없게 할때 사용
	//         java, C# 은 앞쪽에 표기, C++은 뒷쪽에 표기 
	virtual void draw() final
	{
		std::cout << "mutex lock" << std::endl;
		draw_imp();
		std::cout << "mutex unlock" << std::endl;
	}





	virtual Shape* clone()
	{
		Shape* p = new Shape;
		p->color = color;

		return p;
	}

	virtual int get_area() { return -1; }
};





class Rect : public Shape
{
public:
	virtual void draw_imp() override { std::cout << "draw rect" << std::endl; }

	virtual Shape* clone() override
	{
		return new Rect(*this); // 복사 생성자로 생성. 
	}
};


class Circle : public Shape
{
public:
	virtual void draw_imp() override { std::cout << "draw circle" << std::endl; }

	virtual Shape* clone() override
	{
		return new Circle(*this);
	}
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

			v.push_back(v[k]->clone()); 
		}
	}
}

