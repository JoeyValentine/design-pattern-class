#include <iostream>


int main()
{
	slist<int> s = { 1,2,3,4,5 }; // 모든 요소가 떨어진 메모리
	vector<int> v = { 1,2,3,4,5 }; // 모든 요소가 연속된 메모리

	// 반복자(iterator) 패턴의 기본 개념
	// => 컨테이너(복합객체)의 내부구조에 상관없이 동일한 방법으로
	//    모든 요소를 열거할수 있게 한다.
	// => C#, 타이젠(C++) 에서는 "열거자(enumerator)" 라고도 합니다.


	// 목표 1. 모든 컨테이너에서는 iterator 객체를 꺼낼수 있어야 한다
	// => 모든 컨테이너는 "iterator()" 함수가 있어야 한다.
	// => 인터페이스로 약속 한다.!!
	slist_iterator  p1 = s.iterator();
	vector_iterator p2 = v.iterator();


	// 목표 2. 모든 iterator 는 사용법이 동일해야 한다.
	// => 모든 반복자가 지켜야하는 인터페이스가 필요 하다.
	while (p1.hasNext()) //끝에 도달 ?
	{
		// 요소 얻기
		std::cout << p1.next() << std::endl;
	}

}