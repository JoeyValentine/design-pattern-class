#include <iostream>

// å���� ����(��)(chain of responsibility) - 179 page
// => �θ� ���Ǵ� ���� �Դϴ�.




// å���� ���� ������ �⺻ ������ �����ִ� �ڵ� �Դϴ�.
struct Handler
{
	// ��û�� ó���ϴ� ���� ��ü
	Handler* next = nullptr;

	// ��û�� �߻��ϸ� ���Լ��� ���޵ȴ�.
	void Handle(int problem)
	{
		// 1. �ڽ��� ���� ó���� �õ� �Ѵ�.
		// => ��û�� �ذ�Ǿ�����, ����!!
		if (HandleRequest(problem) == true)
			return;

		// 2. ó������ ���� ���� ���� ��ü�� �����Ѵ�.
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

	// mh => oh => th ������ ��û�� ���޵˴ϴ�.

//	mh.Handle(99);
//	mh.Handle(110);
//	mh.Handle(10);
	mh.Handle(12);
}
