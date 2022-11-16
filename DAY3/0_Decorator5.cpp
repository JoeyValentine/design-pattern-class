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
		printf("%s ����\n", buff.c_str() );
	}
};

int main()
{
	// C����� ������ : �����ڰ� ���� �ڿ��� �����ؾ� �Ѵ�.
	FILE* f = fopen("a.txt", "wt");
	fclose(f);

	// ��ü����(C++) �� ����ϸ�
	// => ������/�Ҹ��ڷ� �ڿ� ������ �ϸ� �˴ϴ�.
	FileStream fs("a.txt");
	fs.Write("hello");
}