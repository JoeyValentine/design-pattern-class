#include <iostream>
#include <string>
#include <conio.h>

// 변하는 것을 분리하는 2가지 기술
// 1. 변하는 것을 가상함수로 - Edit2. template method
// 2. 변하는 것을 다른 클래스로!

// 입력값을 Validation 하는 정책 클래스의 규칙(인터페이스)
struct IValidator
{
	virtual bool validate(const std::string& s, char c) = 0;
	virtual bool iscomplete(const std::string& s){return true;}
	virtual ~IValidator() {}
};

// 주민 번호 : 901   1     확인버튼



class Edit
{
	std::string data;
	//==========================================
	IValidator* pval = nullptr;
public:
	void setValidator(IValidator* p) { pval = p; }
	//==================================


	std::string getData()
	{
		data.clear();

		while (true)
		{
			char c = _getch();

			if (c == 13 && (pval == nullptr || pval->iscomplete(data)) ) break;

			if ( pval == nullptr || pval->validate(data, c) )
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

	// 현재 상태는 e 에 "validation 정책"을 연결하지 않았습니다.
	// => 모든 문자 입력 가능

	while (1)
	{
		std::cout << e.getData() << std::endl;
	}
}


