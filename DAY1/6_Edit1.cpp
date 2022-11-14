#include <iostream>
#include <string>
#include <conio.h>

// 입력값의 "Validation" 기능 추가!


class Edit
{
	std::string data;
public:
	std::string getData()
	{	
		data.clear();

		while (true)
		{
			char c = _getch();// 한자만 입력(화면 출력 안됨)

			if (c == 13) break;	// enter

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


