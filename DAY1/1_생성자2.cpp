// 1_생성자2-1.cpp
#include <string>
#include <iostream>

class People
{
	std::string name;
	int age;
public:
	People(const std::string& n, int a) : name(n), age(a)
	{
	}
};
int main()
{
//	People p1;	// 이렇게 객체를 만들수 있다는 것이 좋을까요 ? 
				// (초기화 되지 않은 객체)
				// => 좋지 않습니다.
				// => 되도록 모든 객체는 유효하게(안전하세)생성되어야합니다.

	People p2("kim", 20); // ok.. 초기화된 객체
}


