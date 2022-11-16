#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

struct Stream
{
	virtual void Write(const std::string& s) = 0;
	virtual ~Stream() {}
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
	// File 에 데이타를 Write 할때, 암호화 해서 쓰고 싶다..!!
	// => 어떻게 하는 것이 최선일지를 생각해 봅시다.


	// 방법 1. 데이타를 암호화하고 Write 한다.
	// => 이런 작업을 자주하게 되면 불편하다.

	// 방법 2. FileStream 의 멤버로 WriteEncrypt() 추가
	// => NetworkStream, PipeStream 에도 추가해야 한다.

	// 방법 3. 기반 클래스인 Stream 에 WriteEncrypt() 추가
	// => 압축해서 쓰기, 암호화 해서쓰기, XML 로 쓰기등
	// => 새로운 요구사항이 생길때 마다 "Stream" 에 추가할수는 없다.
	// => OCP 위반!!!

	// 방법 4. 새로운 요구조건을 "FileStream(NetworkStrem)"에
	//        추가하는 Decorator 패턴 사용. 

	FileStream fs("a.txt");
	fs.Write("hello");      // 그냥 파일에 쓰기

	EncryptDecorator ed(&fs);
	ed.Write("hello");		// 1. 데이타를 암호하는 기능 수행
							// 2. fs.Write() 수행

	ZipDecorator zd(&ed);
	zd.Write("hello");	// 1. 데이타를 압축하는 기능 수행
						// 2. ed.Write() 수행

}