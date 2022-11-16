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

int main()
{
	// File �� ����Ÿ�� Write �Ҷ�, ��ȣȭ �ؼ� ���� �ʹ�..!!
	// => ��� �ϴ� ���� �ּ������� ������ ���ô�.


	// ��� 1. ����Ÿ�� ��ȣȭ�ϰ� Write �Ѵ�.
	// => �̷� �۾��� �����ϰ� �Ǹ� �����ϴ�.

	// ��� 2. FileStream �� ����� WriteEncrypt() �߰�
	// => NetworkStream, PipeStream ���� �߰��ؾ� �Ѵ�.

	// ��� 3. ��� Ŭ������ Stream �� WriteEncrypt() �߰�
	// => �����ؼ� ����, ��ȣȭ �ؼ�����, XML �� �����
	// => ���ο� �䱸������ ���涧 ���� "Stream" �� �߰��Ҽ��� ����.
	// => OCP ����!!!

	// ��� 4. ���ο� �䱸������ "FileStream(NetworkStrem)"��
	//        �߰��ϴ� Decorator ���� ���. 

	FileStream fs("a.txt");
	fs.Write("hello");      // �׳� ���Ͽ� ����

	EncryptDecorator ed(&fs);
	ed.Write("hello");		// 1. ����Ÿ�� ��ȣ�ϴ� ��� ����
							// 2. fs.Write() ����

	ZipDecorator zd(&ed);
	zd.Write("hello");	// 1. ����Ÿ�� �����ϴ� ��� ����
						// 2. ed.Write() ����

}