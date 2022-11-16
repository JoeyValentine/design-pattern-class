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
// ����ʹ� 2���� ������ �ֽ��ϴ�.
// Ŭ���� ����� : Ŭ������ �������̽�(�Լ��̸�) ����
// ��ü   ����� : ��ü�� �������̽� ����

class Text : public Shape, public TextView
{
public:
	Text(const std::string& s) : TextView(s) {}

	void draw() { TextView::Show(); };
};

int main()
{
	std::vector<Shape*> v;

	TextView tv("hello"); // TextView : Ŭ���� �Դϴ�.
						  // tv		  : ��ü �Դϴ�.

	// �̹� �����ϴ� ��ü "tv" �� v�� �ְ� �ͽ��ϴ�.

	v.push_back( &tv ); // error!!. Shape�� ���� �Ļ����� �ʾҽ��ϴ�.
}







