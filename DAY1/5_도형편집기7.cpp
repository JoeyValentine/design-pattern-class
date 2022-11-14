#include <iostream>
#include <vector>

// 10. 가상함수 vs 순수 가상함수
// 가상함수 : 재정의(override) 하지 않으면 디폴트 구현을 제공하겠다는의미
// 순수 가상함수 : 반드시 파생 클래스에서 구현을 제공하라 는 의미.

class NotImplemented {};

class Shape
{
	int color;
public:
	virtual ~Shape() {}

	void set_color(int c) { color = c; }
	int  get_color() { return color; }

	virtual void draw() final
	{
		std::cout << "mutex lock" << std::endl;
		draw_imp();
		std::cout << "mutex unlock" << std::endl;
	}


protected:
	// 1. 반드시 파생 클래스가 만들라고 지시 하는 것
	virtual void draw_imp() = 0;

public:
	// 2. 디폴트 구현으로 예외 발생
	// override 하지 않고, 사용하지도 않으면 ok
	// override 하지 않고, 사용하면 예외 발생
	// override 하고,     사용하면 ok. 
	virtual Shape* clone() { throw NotImplemented(); return 0; }

	// 3. 디폴트 구현으로 "면적을 구할수 없음" 으로 약속된 값 반환
	virtual int get_area()  { return -1; }
};





class Rect : public Shape
{
public:
	virtual void draw_imp() override { std::cout << "draw rect" << std::endl; }

	virtual Shape* clone() override
	{
		return new Rect(*this); 
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

