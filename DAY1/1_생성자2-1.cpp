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
	// 핵심 1. 기반 클래스인 People 에 디폴트 생성자가 없습니다.
	// => 아래처럼 하면 컴파일러가 "People()" 를 호출하는 코드를 생성합니다.
//	Student(int n) : id(n) {} // Student(int n) : People(), id(n) {} 

	// 핵심 2. 기반 클래스의 생성자를 명시적으로 호출해야 합니다.
	Student(const std::string& name, int age, int n) 
		: People(name, age), id(n) {}
};

int main()
{
	// Student 객체 생성해 보세요.. 
	Student s("kim", 30, 15); // ok
}

// 초기화 리스트 문법
class Student : public People
{
	멤버 데이타 n;
public:
	// 코드 순서 변경해서, 실행은 기반 클래스 생성자가 먼저 실행됩니다.
//	Student() : 기반클래스생성자(), 멤버 데이타 초기화() {}
//	Student() : 멤버 데이타 초기화(),  기반클래스생성자()  {}
				// => 이렇게 해도 기반 클래스 부터!
};
