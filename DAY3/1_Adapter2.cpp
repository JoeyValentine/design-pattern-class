#include <iostream>
#include <string>
#include <vector>

class TextView
{
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
//==========================================
// 어답터는 2가지 종류가 있습니다.
// 클래스 어답터 : 클래스의 인터페이스(함수이름) 변경
// 객체   어답터 : 객체의 인터페이스 변경

class Text : public Shape, public TextView
{
public:
	Text(const std::string& s) : TextView(s) {}

	void draw() { TextView::Show(); };
};

int main()
{
	std::vector<Shape*> v;

	Shape* p = new Text("hello");     // ok

	v.push_back(p);
}







