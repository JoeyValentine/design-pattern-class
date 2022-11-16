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

class EncryptDecorator : public Stream
{
	Stream* stream;
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

class StreamAdapter
{
	Stream* stream;
public:
	StreamAdapter(Stream* s) : stream(s) {}

	// Write() => WriteFormat() ���� �������̽� ����
	void WriteFormat(const std::string& s, ...)
	{
		// �������ڷ� ���� ����Ÿ�� ���ڿ��� �����ؼ� s�� ���̼���
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
	// Stream �� ������ "Write(���ڿ�)" ���·� ����ؾ� �մϴ�.
	fs.Write("hello");


	// �׷���, ���� ���� ����ȭ�� ���ڿ��� stream �� ���� �ͽ��ϴ�.
	int n = 10;
//	fs.WriteFormat("n = %d, %f", n, 3.4);
				// => FileStream �� �߰��ϸ� OCP �����̰�!
				// => �ٸ� Stream ���� �߰��ؾ� �մϴ�. 


	// Write �Լ��� WriteFormat �Լ��� �������ִ� �����
	StreamAdapter sa(&fs);
	sa.WriteFormat("n = % d, % f", n, 3.4);
				// 1. ���ڸ� ���ڿ��� �����ؼ�  <= ����� �߰��ؼ�
				// 2. fs.Write()�� ����.		<= ���� ��ɻ���ϹǷ�
											// Decorator �ƴѰ��� ?

}
// Decorator : ��ü�� ������ ��� �߰�. "�������̽�(�Լ��̸�)�� ����"
//			   Decorator �, FileStream �� ������ �������̽�(�Լ��̸�) ����

// adapter : �������̽��� ����(Write() => WriteFormat())
//			 ������ �������̽��� ����ϸ鼭 ����߰��� �ƴ϶�!!!
//			 �������̽��� ����Ǵ°� �Ǵ� ����Ǹ鼭 ����߰�