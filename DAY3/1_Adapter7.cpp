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

class EncryptDecorator : public Stream
{
	Stream* stream;
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

class StreamAdapter
{
	Stream* stream;
public:
	StreamAdapter(Stream* s) : stream(s) {}

	// Write() => WriteFormat() 으로 인터페이스 변경
	void WriteFormat(const std::string& s, ...)
	{
		// 가변인자로 받은 데이타를 문자열로 변경해서 s에 붙이세요
		stream->Write(s);
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

	//===============================
	// Stream 에 쓰려면 "Write(문자열)" 형태로 사용해야 합니다.
	fs.Write("hello");


	// 그런데, 변수 값을 서식화된 문자열로 stream 에 쓰고 싶습니다.
	int n = 10;
//	fs.WriteFormat("n = %d, %f", n, 3.4);
				// => FileStream 에 추가하면 OCP 위반이고!
				// => 다른 Stream 에도 추가해야 합니다. 


	// Write 함수를 WriteFormat 함수로 변경해주는 어답터
	StreamAdapter sa(&fs);
	sa.WriteFormat("n = % d, % f", n, 3.4);
				// 1. 인자를 문자열로 변경해서  <= 기능을 추가해서
				// 2. fs.Write()에 전달.		<= 원래 기능사용하므로
											// Decorator 아닌가요 ?

}
// Decorator : 객체에 동적인 기능 추가. "인터페이스(함수이름)을 동일"
//			   Decorator 등도, FileStream 과 동일한 인터페이스(함수이름) 유지

// adapter : 인터페이스의 변경(Write() => WriteFormat())
//			 동일한 인터페이스를 사용하면서 기능추가가 아니라!!!
//			 인터페이스가 변경되는것 또는 변경되면서 기능추가