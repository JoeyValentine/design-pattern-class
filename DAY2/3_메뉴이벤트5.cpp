// 3_메뉴이벤트5
#include <iostream>
#include <functional>

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
	std::bind(&foo, 1, 2, 3, 4)();
}