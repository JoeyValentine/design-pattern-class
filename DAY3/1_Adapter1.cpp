#include <iostream>
#include <string>
#include <vector>

// 아래 클래스가 이미 있었다가 가정해 봅시다.
// 기능 : 문자열을 보관했다가 "화면에 이쁘게 출력"

class TextView
{
	// font 종류, 크기, bold, 색상
	std::string data;
public:
	TextView(const std::string& s) : data(s) {}

	void Show() { std::cout << data << std::endl; }
};

//===========================================

class Shape
{
public:
	virtual void draw() = 0;
	virtual ~Shape() {}
};


class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw rect" << std::endl; }
};
class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw circle" << std::endl; }
};

// 도형편집기 시스템에 "문자열"도 추가하고 싶다.
// => 예전 부터 사용하던 "TextView" 가 있다!!
// => 도형편집기 시스템에서 "TextView" 를 사용할수 있을까 ??

// TextView 를 도형편집기 시스템이 요구하는 인터페이스로 변경!!
class Text : public Shape, public TextView
{
public:
	Text(const std::string& s) : TextView(s) {}

	void draw() { ? };
};




int main()
{
	std::vector<Shape*> v;
}







