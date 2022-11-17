#include <iostream>

int main()
{
	// 문자열 배열 vs 문자열 포인터
	char sa[]      = "hello"; // 문자열은 "스택"에
	const char* sp = "hello"; // 문자열은 "상수 메모리에"
//	char* sp = "hello"; // C언어는 이코드를 허용하지만
//	*sp = 'A'; // 이순간 runtime eror.. 상수 메모리는 쓸수 없다.

	//-----------------------

	char sa1[] = "hello";
	char sa2[] = "hello";

	const char* sp1 = "hello";
	const char* sp2 = "hello";

	printf("%p, %p\n", sp1, sp2);
}