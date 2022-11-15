// 3_메뉴이벤트5
#include <iostream>
#include <functional>
using namespace std::placeholders; // _1, _2, _3....

void foo(int a, int b, int c, int d)
{
	printf("%d, %d, %d, %d\n", a, b, c, d);
}

int main()
{
	foo(1, 2, 3, 4); // 4항함수

	// std::bind : M 항함수의 일부 인자를 고정해서 N 항함수로 만드는 도구
	//			  (단, M > N)
	//            함수형언어의 "currying 기술"의 발전된 개념!

	// 사용법 : std::bind( M항함수주소, M개의 인자)

	std::bind(&foo, 1, 2, 3, 4)(); // 4항함수 => 0항 함수로!
	//<---- 결과가 다시 함수 --->|

	std::bind(&foo, 5, _1, 9, _2)(7, 3); // foo(5,7,9,3)
								// 즉, 4항 => 2항 함수로 변경


	std::bind(&foo, _2, 8 , _3 , _1 )(7, 9, 2); // foo(9, 8, 2, 7)
								// 4항 함수를 3항함수로 변경한것

	// 파이썬에도 위와 같은 도구가 있습니다. : functools.partial 찾아보세요
}