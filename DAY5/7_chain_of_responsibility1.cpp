#include <iostream>

// 책임의 전가(고리)(chain of responsibility) - 179 page
// => 널리 사용되는 패턴 입니다.




// 책임의 전가 패턴의 기본 구조를 보여주는 코드 입니다.
struct Handler
{
	// 요청을 처리하는 다음 객체
	Handler* next = nullptr;

	// 요청이 발생하면 이함수에 전달된다.
	void Handle(int problem)
	{
		// 1. 자신이 먼저 처리를 시도 한다.
		// => 요청이 해결되었으면, 종료!!
		if (HandleRequest(problem) == true)
			return;

		// 2. 처리하지 못한 경우는 다음 객체에 전달한다.
		if (next != 0)
			next->Handle(problem);
	}
	virtual bool HandleRequest(int problem) = 0;
};
//================================
class TenHandler : public Handler
{
public:
	virtual bool HandleRequest(int problem) override
	{
		std::cout << "start TenHandler" << std::endl;

		if (problem == 10)
		{
			std::cout << "resolve by TenHandler" << std::endl;
			return true;
		}
		return false;
	}
};
class MoreThan100Handler : public Handler
{
public:
	virtual bool HandleRequest(int problem) override
	{
		std::cout << "start MoreThan100Handler" << std::endl;

		if (problem > 100)
		{
			std::cout << "resolve by MoreThan100Handler" << std::endl;
			return true;
		}
		return false;
	}
};
class OddHandler : public Handler
{
public:
	virtual bool HandleRequest(int problem) override
	{
		std::cout << "start OddHandler" << std::endl;

		if (problem % 2 == 1)
		{
			std::cout << "resolve by OddHandler" << std::endl;
			return true;
		}
		return false;
	}
};

int main()
{
	TenHandler th;
	OddHandler oh;
	MoreThan100Handler mh;

	mh.next = &oh;
	oh.next = &th;

	// mh => oh => th 순서로 요청이 전달됩니다.

//	mh.Handle(99);
//	mh.Handle(110);
//	mh.Handle(10);
	mh.Handle(12);
}
