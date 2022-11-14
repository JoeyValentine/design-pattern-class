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
	virtual bool iscomplete(const std::string& s) { return true; }
	virtual ~IValidator() {}
};

class Edit
{
	std::string data;
	IValidator* pval = nullptr;
public:
	void setValidator(IValidator* p) { pval = p; }


	std::string getData()
	{
		data.clear();

		while (true)
		{
			char c = _getch();

			if (c == 13 && (pval == nullptr || pval->iscomplete(data))) break;

			if (pval == nullptr || pval->validate(data, c))
			{
				data.push_back(c);

				std::cout << c;
			}
		}

		std::cout << "\n";
		return data;
	}
};
//============================================
// 이제 IValidator 인터페이스를 구현한 다양한 "Validation 정책 클래스"
// 를 제공하면 됩니다.

class LimitDigitValidator : public IValidator
{
	int limit;
public:
	LimitDigitValidator(int n) : limit(n) {}

	virtual bool validate(const std::string& s, char c) override
	{
		return s.size() < limit && isdigit(c);
	}

	virtual bool iscomplete(const std::string& s) override
	{
		return s.size() == limit;
	}
};

int main()
{
	Edit e;
	LimitDigitValidator v(5);
	e.setValidator(&v);  // v 객체를 사용해서 validation 해달라!!


	LimitDigitValidator v2(15);
	e.setValidator(&v2);
	while (1)
	{
		std::cout << e.getData() << std::endl;
	}
}
// strategy(전략패턴)
// => 변하는것을 다른 클래스로
// => 인터페이스 기반 교체
// => 실행시간에 정책 교체 가능
// => Edit 와 정책이 분리되어 있다.
//    다른 입력 도구에서도 정책사용가능