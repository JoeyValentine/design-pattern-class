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




int main()
{
	Edit e;
	while (1)
	{
		std::cout << e.getData() << std::endl;
	}
}


