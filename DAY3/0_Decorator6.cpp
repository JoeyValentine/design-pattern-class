#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

// 모든 종류의 Stream 이 동일한 함수를 사용하는 것을 보장하기 위해
// 인터페이스 설계

struct Stream
{
	virtual void Write(const std::string& s) = 0;
	virtual ~Stream() {}

	// Read, IsOpen() 등의 입출력관련 기본함수의 이름 약속.
};


class FileStream : public Stream 
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
		printf("%s 쓰기\n", buff.c_str());
	}
};

int main()
{
	FileStream fs("a.txt");
	fs.Write("hello");


	// FileStream 외에 다양한 Stream 이 있다고 생각해 봅시다.
//	NetworkStream ns("127.0.0.1", 4000);
//	ns.Write("hello");


//	PipeStream ps("namedpipe");
//	ps.Write("hello");

}