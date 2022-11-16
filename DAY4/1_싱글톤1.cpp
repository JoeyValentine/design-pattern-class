#include <iostream>

// 싱글톤 : 오직 한개의 객체만 존재하는 것.
//         프로그램의 어디에서도 동일한 방법으로 접근 가능한것

class Cursor
{
	// 규칙 1. 생성자를 private !!
private:
	Cursor() {}


	// 규칙 3. 오직 한개의 객체를 만들어서 반환하는 static 멤버 함수
public:
	static Cursor& getInstance()
	{
		static Cursor instance;
		return instance;
	}
};

int main()
{
	Cursor& c1 = Cursor::getInstance();
	Cursor& c2 = Cursor::getInstance();

	std::cout << &c1 << ", " << &c2 << std::endl;

//	Cursor c1, c2; // error
}

