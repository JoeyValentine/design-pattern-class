#include <iostream>
#include <string>
#include <conio.h>

// Validation ����� ����ɼ� �־�� �Ѵ�.


class Edit
{
	std::string data;
public:

	// ���뼺�� �������� �и�
	// => ������ ���� �ڵ� ���ο� �ִ� ���ؾ� �ϴ� �κ��� �и��Ǿ�� �Ѵ�.
	// ��� 1. ���ϴ� �κ��� �����Լ��� �и��Ѵ�.

	virtual bool validate(char c)
	{
		return true;
	}
	std::string getData()
	{
		data.clear();

		while (true)
		{
			char c = _getch();

			if (c == 13) break;	

			if ( validate(c) ) // ���ؾ��ϴ� �ڵ�� - "�����Լ� ȣ��"
			{
				data.push_back(c);
				std::cout << c;
			}
		}
		std::cout << "\n";
		return data;
	}
};

// ���� Validation ��å�� �����Ϸ��� 
// "Edit"�� �Ļ� Ŭ������ ���� "validate" �����Լ��� ������!!
// => ���� �ڵ��� ���� �� �ƴ�, ���� �ڵ��� Ȯ��

class NumEdit : public Edit
{
public:
	virtual bool validate(char c)
	{
		return isdigit(c);
	}
};
int main()
{
//	Edit e;
	NumEdit e;

	// AddressEdit e2;

	while (1)
	{
		std::cout << e.getData() << std::endl;
	}
}


// template method
// => ���ϴ� ���� �����Լ���!
// => ��� ����� ����
// => ����ð� ��å ��ü�� �ɼ� ����.
// => NumEdit �� ��å�� ���� �Ѵ�.
//    NumEdit �� ��å�� NumEdit �� ��밡��