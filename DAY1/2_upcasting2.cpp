// upcasting2.cpp
#include <vector>

class Animal {};
class Dog : public Animal {};
class Cat : public Animal {};

int main()
{
	std::vector<Dog*>    v1; // Dog 객체만 보관하는 vector
	std::vector<Animal*> v2; // 모든 동물을 보관하는 vector
						
	// Upcasting 의 장점(활용) 1.
	// => 동종(기반 클래스가 동일한 타입)을 저장하는 
	//	  컨테이너(컬렉션)를 만들수 있다.

}