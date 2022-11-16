#include <iostream>

// ��� 2. ������ �Ѱ��� ��ü�� "static ��� ����Ÿ"�� �����ϴ� ��

class Cursor
{
//	Cursor instance; // error. �ڽ��� ��ü�� �������Ÿ�� ����� ����.
	static Cursor instance;
private:
	Cursor() {}
	Cursor(const Cursor&) = delete;
	Cursor operator=(const Cursor&) = delete;

public:
	static Cursor& getInstance()
	{
		return instance;
	}
};
Cursor Cursor::instance;

int main()
{
	Cursor& c1 = Cursor::getInstance();
	Cursor& c2 = Cursor::getInstance();

	std::cout << &c1 << ", " << &c2 << std::endl;
}

