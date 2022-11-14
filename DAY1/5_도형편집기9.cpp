#include <iostream>
#include <vector>

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

	virtual Rect* clone() override
	{
		return new Rect(*this);
	}
};

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

		// 생각해볼 문제
		// 1. 객체의 생성과정을 다형성을 사용할수 없을까 ?
		//    => 새로운 도형이 추가되어도 기존 코드는 변화되지 않게
		//    => "추상 팩토리 패턴"을 활용하면 됩니다 - 목요일날 배웁니다.

		// 2. Undo/Redo 기능을 추가하려면 어떻게 해야 할까 ?
		//    => "Command" 패턴을 알면 됩니다. - 목요일날 배웁니다.

		if      (cmd == 1) { v.push_back(new Rect);}
		else if (cmd == 2) { v.push_back(new Circle);}
		else if (cmd == 9)
		{
			for (auto p : v) p->draw(); // 다형성 !
		}
		else if (cmd == 8)
		{
			int k = -1;
			std::cout << "몇번째를 복사할까요 >> ";
			std::cin >> k;

			v.push_back(v[k]->clone()); // 다형성 !
		}
	}
}

