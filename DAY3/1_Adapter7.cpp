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
		printf("%s ¾²±â\n", buff.c_str());
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
		auto newdata = s + " ¾ÏÈ£È­µÊ";
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
		auto newdata = s + " ¾ÐÃàµÊ";
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