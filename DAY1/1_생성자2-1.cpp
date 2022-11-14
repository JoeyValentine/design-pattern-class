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
// People 로부터 상속받은 Student 만들어 보세요
// 멤버 데이타로 학번(id) 추가해 보세요
// => 핵심 : 생성자 만들어 보세요
class Student : public People
{
	int id;
public:
	//
};
int main()
{
	// Student 객체 생성해 보세요.. 
}


