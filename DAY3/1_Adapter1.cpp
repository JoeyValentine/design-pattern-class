#include <iostream>
#include <string>
#include <vector>

// �Ʒ� Ŭ������ �̹� �־��ٰ� ������ ���ô�.
// ��� : ���ڿ��� �����ߴٰ� "ȭ�鿡 �̻ڰ� ���"

class TextView
{
	// font ����, ũ��, bold, ����
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

// ���������� �ý��ۿ� "���ڿ�"�� �߰��ϰ� �ʹ�.
// => ���� ���� ����ϴ� "TextView" �� �ִ�!!
// => ���������� �ý��ۿ��� "TextView" �� ����Ҽ� ������ ??

// TextView �� ���������� �ý����� �䱸�ϴ� �������̽��� ����!!

// Adapter ���� : �������̽��� ����ġ�� �ذ��ϴ� ����
//				 ���� Ŭ������ �������̽�(�Լ��̸�)�� �����ؼ�
//				 �䱸���ǿ� �°� �������ִ� Ŭ������ ����� ����

class Text : public Shape, public TextView
{
public:
	Text(const std::string& s) : TextView(s) {}

	void draw() { TextView::Show(); };
};

int main()
{
	std::vector<Shape*> v;

//	Shape* p = new TextView("hello"); // error
	Shape* p = new Text("hello");     // ok

	v.push_back(p);
}







