#include <iostream>
#include <list> // C++ 표준 더블리스트
#include <forward_list> // 싱글리스트
#include <vector>		// 연속된 메모리의 컨테이너

int main()
{
	std::list<int> ds = { 1,2,3,4,5 }; // 더블 링크드 리스트
	std::forward_list<int> fs = { 1,2,3,4,5 }; // 싱글 링크드 리스트

	auto p1 = ds.begin();  // 더블리스트의 반복자 : 양방향 반복자
	auto p2 = fs.begin();  // 싱글리스트의 반복자 : 전진형 반복자(--안됨)

	// 다음중 에러를 찾으세요
	++p1;	
	++p2;
	--p1;
	--p2; // error
}