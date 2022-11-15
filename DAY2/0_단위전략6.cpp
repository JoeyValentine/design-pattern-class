#include <iostream>
#include <vector>
#include <allocators> // C++ 표준 메모리 할당기

int main()
{
	// C/C++ 에는 메모리를 할당/해지 하는 많은 방법이 있습니다
	// => new, delete
	// => malloc, free
	// => linux system call, windows win32 api
	// => 메모리 풀링

	// 메모리 할당 방법
	// 1. new / delete 를 직접 사용
	// => 만약 메모리 할당 방식을 변경한다면
	// => 아래 코드 전체를 변경해야 합니다.
	int* p1 = new int[10];
	delete[] p1;

	int* p2 = new int[10];
	delete[] p2;


	// 2. allocator 사용
	// => 메모리 할당/해지 정책을 담은 클래스
	std::allocator<int> ax;  // 표준 할당기 - new / delete 사용


	int* p = ax.allocate(10); // 표준 할당기라면 "new int[10]"

	ax.deallocate(p, 10);	// 표준 할당기라면 "delete[] p"

}