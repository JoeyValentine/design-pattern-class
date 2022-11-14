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

// 이제 Validation 정책을 변경하려면 
// "Edit"의 파생 클래스를 만들어서 "validate" 가상함수를 재정의!!
// => 기존 코드의 변경 이 아닌, 기존 코드의 확장

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
// => 변하는 것을 가상함수로!
// => 상속 기반의 패턴
// => 실행시간 정책 교체는 될수 없다.
// => NumEdit 가 정책을 포함 한다.
//    NumEdit 의 정책은 NumEdit 만 사용가능
