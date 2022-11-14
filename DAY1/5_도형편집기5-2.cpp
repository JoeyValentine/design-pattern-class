#include <iostream>
#include <vector>

// 6. 리팩토링 ( 기존 코드의 구조를 보다 좋은 구조로 변경하는 분야)
// => "Replace Conditional With Polymorphism"
//    "제어문(예제5-1)을 다형성(가상함수, 예제5-2)으로 변경하라!"
//   


// 7. 디자인 패턴
// => 1994년 4명의 C++ 개발자가 저술한 책!
// => 당시 유행하던 코딩 기법(스타일)에 "이름을 부여" 한것
// => 23개의 이름!!!

// 8. prototype 패턴 : 견본이 되는 객체를 만들어서
//					  복사를 통해 객체를 생성하는 디자인 기본
//					  clone() 가상함수
//                    java 의 object 클래스 안에 clonable() 메소드
//					  C# IClonable 인터페이스
//					  Objective-C 의 copy 함수
//					 모두 이 패턴의 응용 기술!!


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

