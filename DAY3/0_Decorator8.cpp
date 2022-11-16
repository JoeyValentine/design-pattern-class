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
//================================================
// 다양한 Stream 에 기능을 추가하는 객체들 
class EncryptDecorator : public Stream
{
	Stream* stream;	 // Decorator 가 인터페이스 포함

	// 암호화작업에 필요한 다양한 멤버 데이타 추가!!
public:
	EncryptDecorator(Stream* s) : stream(s) {}


	void Write(const std::string& s)
	{
		auto newdata = s + " 암호화됨";
		stream->Write(newdata);
	}
};
class ZipDecorator : public Stream
{
	Stream* stream;	 
public:
	ZipDecorator(Stream* s) : stream(s) {}


	void Write(const std::string& s)
	{
		auto newdata = s + " 압축됨";
		stream->Write(newdata);
	}
};


int main()
{
	FileStream fs("a.txt");
	fs.Write("hello");      

	EncryptDecorator ed(&fs);
	ed.Write("hello");		

	ZipDecorator zd(&ed);
	zd.Write("hello");	

}