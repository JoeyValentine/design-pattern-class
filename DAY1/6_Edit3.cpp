#include <iostream>
#include <string>
#include <conio.h>

// ���ϴ� ���� �и��ϴ� 2���� ���
// 1. ���ϴ� ���� �����Լ��� - Edit2. template method
// 2. ���ϴ� ���� �ٸ� Ŭ������!


class Edit
{
	std::string data;
public:
	std::string getData()
	{
		data.clear();

		while (true)
		{
			char c = _getch();

			if (c == 13) break;	

			if (isdigit(c))
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


