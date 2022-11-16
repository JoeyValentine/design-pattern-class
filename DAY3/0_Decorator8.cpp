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
// 미래에 Stream 에 새로운 기능이 요구되면
// => 해당 기능을 가지는 새로운 Decorator 만 만들면 됩니다.
// => 기존 Stream 클래스를 변경하지 않고, 계속 기능이 추가됩니다.

int main()
{
	FileStream fs("a.txt");
	fs.Write("hello");      

	EncryptDecorator ed(&fs);
	ed.Write("hello");		

	ZipDecorator zd(&ed);
	zd.Write("hello");	
}
// C# 언어의 입출력 스트림
// 저장소					StreamDecorator 들
// FileStream			EncryptStream
// NetworkStream		GZipStream
// PipeStream			XmlStream
// MemoryStream			HtmlStream	

// strategy  : 알고리즘의 "교체"(변경)
// decorator : 기능의 "추가"
//				중첩해서 계속 추가 가능
//				"포장지는 객체를 포장하지만, 포장된 객체도 포장할수 있다."

// 파이썬에도 "decorator" 라는 문법이 있습니다
// @static 처럼 "@" 로 시작하는 문법
// 
// => 전통적인 디자인 패턴 처럼 클래스로 만드는 것은 아니지만
// => "함수"에 기능추가(호출 전/후 필터)라는 관점에서는 동일합니다.