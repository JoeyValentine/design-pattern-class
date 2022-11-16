#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

class FileStream
{
	FILE* file;
public:
	FileStream(const char* s, const char* mode = "wt")
	{
		file = fopen(s, mode);
	}
	~FileStream() { fclose(file); }

	void Write(const std::string& buff) 
	{
		printf("%s 쓰기\n", buff.c_str() );
	}
};

int main()
{
	// C언어의 문제점 : 개발자가 직접 자원을 관리해야 한다.
	FILE* f = fopen("a.txt", "wt");
	fclose(f);

	// 객체지향(C++) 을 사용하면
	// => 생성자/소멸자로 자원 관리를 하면 됩니다.
	FileStream fs("a.txt");
	fs.Write("hello");
}