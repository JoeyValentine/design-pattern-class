#define USING_GUI
#include "cppmaster.h"
#include "ICalc.h"


class Calc : public ICalc
{
	int server;
	int refcnt = 0;	// 몇개의 포인터가 현재 객체를 사용하는지 관리
					// "reference counting" 이라는 불리는 기술
public:
	Calc() { server = ec_find_server("Calc"); }

	~Calc() { std::cout << "~Calc" << std::endl; }

	void AddRef() { ++refcnt; }

	void Release() { if (--refcnt == 0) delete this; }




	int Add(int a, int b) { return ec_send_server(server, 1, a, b); }
	int Sub(int a, int b) { return ec_send_server(server, 2, a, b); }
};


extern "C" __declspec(dllexport)
ICalc * Create()
{
	return new Calc;
}


