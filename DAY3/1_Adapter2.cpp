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

// 클래스 어답터 입니다.
class Text : public Shape, public TextView
{
public:
	Text(const std::string& s) : TextView(s) {}

	void draw() { TextView::Show(); };
};

// 아래 코드가 "객체 어답터" 입니다.
class Text2 : public Shape
{
	TextView* txtView; // 핵심 : 포인터 또는 참조로 포함
						// 외부에 이미 생성되어 있는 객체를 
						// 가리키겠다는 의도!!
public:
	Text2(TextView* tv) : txtView(tv) {}
	void draw() { txtView->Show(); };
};
int main()
{
	std::vector<Shape*> v;

	TextView tv("hello"); // TextView : 클래스 입니다.
						  // tv		  : 객체 입니다.

	// 이미 존재하는 객체 "tv" 를 v에 넣고 싶습니다.

	//v.push_back( &tv ); // error!!. Shape로 부터 파생되지 않았습니다.

	v.push_back( new Text2(&tv) );
}







