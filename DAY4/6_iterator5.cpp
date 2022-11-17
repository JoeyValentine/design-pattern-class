#include <iostream>
#include <list> // C++ 표준 더블리스트
#include <forward_list> // 싱글리스트
#include <vector>		// 연속된 메모리의 컨테이너

int main()
{
	// 핵심 1. C++ 표준 반복자 사용하기
	std::list<int> ss = { 1,2,3,4,5 };

	auto p1 = ss.begin();	// 1번째 요소를 가리키는 반복자
	auto p2 = ss.end();		// 마지막 다음

	while (p1 != p2)
	{
		std::cout << *p << std::endl;
		++p1;
	}
}