#include <iostream>
#include <vector>

// 코드 개선

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
	virtual void draw_imp() = 0;

public:
	virtual Shape* clone() { throw NotImplemented(); return 0; }

	virtual int get_area() { return -1; }
};





class Rect : public Shape
{
public:
	virtual void draw_imp() override { std::cout << "draw rect" << std::endl; }

	// 가상 함수의 반환 타입은 "상속관계의 타입"으로 변경 가능합니다
	// 대부분의 객체지향 언어가 지원
	// "공변 반환의 법칙" 이라고 합니다.
	virtual Rect* clone() override
	{
		return new Rect(*this);
	}
};
// Rect* p1 = new Rect;
// Rect* p2 = p1->clone(); // 이렇게 받고 싶다면
//						  clone 의 반환 타입이 Rect* 이어야 합니다.

class Circle : public Shape
{
public:
	virtual void draw_imp() override { std::cout << "draw circle" << std::endl; }

	virtual Circle* clone() override
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

