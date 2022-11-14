#include <iostream>
#include <string>
#include <conio.h>

// ���ϴ� ���� �и��ϴ� 2���� ���
// 1. ���ϴ� ���� �����Լ��� - Edit2. template method
// 2. ���ϴ� ���� �ٸ� Ŭ������!

// �Է°��� Validation �ϴ� ��å Ŭ������ ��Ģ(�������̽�)
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
// ���� IValidator �������̽��� ������ �پ��� "Validation ��å Ŭ����"
// �� �����ϸ� �˴ϴ�.

class LimitDigitValidator : public IValidator
{
	int limit;
public:
	LimitDigitValidator(int n) : limit(n) {}

	virtual bool validate(const std::string& s, char c) override
	{
		return s.size() < limit && isdigit(c);
	}
};

int main()
{
	Edit e;
	LimitDigitValidator v(5);
	e.setValidator(&v);  // v ��ü�� ����ؼ� validation �ش޶�!!

	while (1)
	{
		std::cout << e.getData() << std::endl;
	}
}


