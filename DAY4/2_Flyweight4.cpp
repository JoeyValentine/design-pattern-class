#include <iostream>

int main()
{
	// 문자열 배열 vs 문자열 포인터
	char sa[]      = "hello";
	const char* sp = "hello";

	//-----------------------

	char sa1[] = "hello";
	char sa2[] = "hello";

	const char* sp1 = "hello";
	const char* sp2 = "hello";
}