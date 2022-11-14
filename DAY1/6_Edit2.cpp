#include <iostream>
#include <string>
#include <conio.h>

// Validation 기능은 변경될수 있어야 한다.


class Edit
{
	std::string data;
public:

	// 공통성과 가변성의 분리
	// => 변하지 않은 코드 내부에 있는 변해야 하는 부분은 분리되어야 한다.
	// 방법 1. 변하는 부분을 가상함수로 분리한다.

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

			if ( validate(c) ) // 변해야하는 코드는 - "가상함수 호출"
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


