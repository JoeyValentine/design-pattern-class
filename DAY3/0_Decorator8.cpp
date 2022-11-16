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
		printf("%s ����\n", buff.c_str());
	}
};
//================================================
// �پ��� Stream �� ����� �߰��ϴ� ��ü�� 
class EncryptDecorator : public Stream
{
	Stream* stream;	 // Decorator �� �������̽� ����

	// ��ȣȭ�۾��� �ʿ��� �پ��� ��� ����Ÿ �߰�!!
public:
	EncryptDecorator(Stream* s) : stream(s) {}


	void Write(const std::string& s)
	{
		auto newdata = s + " ��ȣȭ��";
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
		auto newdata = s + " �����";
		stream->Write(newdata);
	}
};
// �̷��� Stream �� ���ο� ����� �䱸�Ǹ�
// => �ش� ����� ������ ���ο� Decorator �� ����� �˴ϴ�.
// => ���� Stream Ŭ������ �������� �ʰ�, ��� ����� �߰��˴ϴ�.

int main()
{
	FileStream fs("a.txt");
	fs.Write("hello");      

	EncryptDecorator ed(&fs);
	ed.Write("hello");		

	ZipDecorator zd(&ed);
	zd.Write("hello");	
}
// C# ����� ����� ��Ʈ��
// �����					StreamDecorator ��
// FileStream			EncryptStream
// NetworkStream		GZipStream
// PipeStream			XmlStream
// MemoryStream			HtmlStream	

// strategy  : �˰����� "��ü"(����)
// decorator : ����� "�߰�"
//				��ø�ؼ� ��� �߰� ����
//				"�������� ��ü�� ����������, ����� ��ü�� �����Ҽ� �ִ�."

// ���̽㿡�� "decorator" ��� ������ �ֽ��ϴ�
// @static ó�� "@" �� �����ϴ� ����
// 
// => �������� ������ ���� ó�� Ŭ������ ����� ���� �ƴ�����
// => "�Լ�"�� ����߰�(ȣ�� ��/�� ����)��� ���������� �����մϴ�.