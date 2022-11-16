#include <iostream>

// 방법 2. 유일한 한개의 객체를 "static 멤버 데이타"로 생성하는 모델
// => Cursor 를 한번도 사용하지 않아도 메모리에 생성된다.!!
// => 1번 모델은 최초 사용시 생성

class Cursor
{
//	Cursor instance; // error. 자신의 객체를 멤버데이타로 만들수 없다.
	static Cursor instance;
private:
	Cursor() { std::cout << "Cursor()" << std::endl; }
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
//	Cursor& c1 = Cursor::getInstance();
//	Cursor& c2 = Cursor::getInstance();
//	std::cout << &c1 << ", " << &c2 << std::endl;
}

