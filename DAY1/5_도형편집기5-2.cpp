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


	// 자신의 복사본을 생성하는 가상함수는 항상 유용하게 사용됩니다.
	virtual Shape* clone()
	{
		Shape* p = new Shape;
		p->color = color; // 모든 멤버를 복사 해서 동일한 객체로.

		return p;
	}
};





class Rect : public Shape
{
public:
	virtual void draw() override { std::cout << "draw rect" << std::endl; }

	virtual Shape* clone() override 
	{
		return new Rect(*this); // 복사 생성자로 생성. 
	}
};


class Circle : public Shape
{
public:
	virtual void draw() override { std::cout << "draw circle" << std::endl; }

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

			v.push_back( v[k]->clone() ); // 다형성!!!
						// => k번째 도형을 알 필요(조사할필요)없다!
						// => 단지, 복사본 만들어 달라고 요청하면!
						// => 새로운 도형이 추가되어도 이 코드는
						//    수정되지 않는다.
						//    OCP 만족!!
		}
	}
}

