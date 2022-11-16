#include <iostream>

// �̱��� : ���� �Ѱ��� ��ü�� �����ϴ� ��.
//         ���α׷��� ��𿡼��� ������ ������� ���� �����Ѱ�
// => �ᱹ "��������" �� �����ϴ�.
// => "��������" �� ���� ���ڴٰ� �̾߱� �մϴ�.
// => ��Ƽ �����忡 �������� �ʰ�, �Լ��� ���������� �и��ϱ⵵ ��������ϴ�.
//========================================================

// ��� 1. �����Ѱ��� ��ü�� "static ��������"�� ���� ��..
// => "effective-c++" �� ������ "scott meyer" �� ó�� ����
// => "meyer's singleton" �̶�� �Ҹ��� ��.


class Cursor
{
	// ��Ģ 1. �����ڸ� private !!
private:
	Cursor() {}

	// ��Ģ 2. �����Ϸ��� ���� �����ڿ� ���Կ����ڸ� ������
	//        �ʵ����ؾ� �Ѵ�.
	// => C++11 �Լ� ���� ���� ���
	// => ���� ������ ������ ���Կ����ڵ� �����ϴ� ���� ����!!
	Cursor(const Cursor&) = delete;
	Cursor operator=(const Cursor&) = delete;				

	// ��Ģ 3. ���� �Ѱ��� ��ü�� ���� ��ȯ�ϴ� static ��� �Լ�
public:
	static Cursor& getInstance()
	{
		static Cursor instance;
		return instance;
	}
};

int main()
{
	Cursor& c1 = Cursor::getInstance();
	Cursor& c2 = Cursor::getInstance();

	std::cout << &c1 << ", " << &c2 << std::endl;

//	Cursor c3 = c1; // ���� ������ ��� �ϴ°͵� ���ƾ� �Ѵ�.


//	Cursor c1, c2; // error
}

