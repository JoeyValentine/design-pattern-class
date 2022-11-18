#include <iostream>
#include <list>
#include <vector>

// visitor 패턴
// 
// 반복자(iterator) : 복합객체의 모든 요소를 "동일한 방식으로 열거"
// 방문자(visitor)  : 복합객체의 모든 요소를 "동일한 방식으로 연산수행"


int main()
{
	std::list<int> s = { 1,2,3,4,5,6,7,8,9,10 };

	// 복합객체의 모든 요소에 연산을 하고 싶을때!!
	
	// 방법 1. 직접 모든 요소를 순회 하면서 연산수행
	// s의 모든 요소를 2배로 하고 싶다.
	for (auto& e : s)
		e *= 2;

	// s 의 모든 요소를 출력하고 싶다.
	for (auto& e : s)
		std::cout << e << ", ";
	std::cout << std::endl;


	// 방법 2. 방문자 패턴을 사용한다.
	TwiceVisitor<int> tv;	// 모든 요소를 2배로 하는 방문자
	s.Accept(&tv);			

	ShowVisitor<int> sv;	// 모든 요소를 출력하는 방문자
	s.Accept(&sv);
}





