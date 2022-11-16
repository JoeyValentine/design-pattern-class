#include <iostream>

// 방법 2. 유일한 한개의 객체를 "static 멤버 데이타"로 생성하는 모델

class Cursor
{
//	Cursor instance; // error. 자신의 객체를 멤버데이타로 만들수 없다.
	static Cursor instance;
private:
	Cursor() {}
	Cursor(const Cursor&) = delete;
	Cursor operator=(const Cursor&) = delete;

public:
	static Cursor& getInstance()
	{
		return instance;
	}
};
Cursor Cursor::instance;

int main()
{
	Cursor& c1 = Cursor::getInstance();
	Cursor& c2 = Cursor::getInstance();

	std::cout << &c1 << ", " << &c2 << std::endl;
}

