#define USING_GUI
#include "cppmaster.h"

// 결국 이 코드는 "다른 프로세스의 함수를 호출" 하고 있습니다.

// RPC : Remote Procedure Call
// RMI : Remote Method Invocation( java, C# )


// Proxy 는 서버의 대행자 이므로
// 서버와 동일한 기능을 제공하는 것을 보장하는 것이 좋습니다.
// => 인터페이스를 설계 합니다.
// => 서버와 Proxy 를 만들때 모두 아래 인터페이스를 구현해야 합니다.
struct ICalc
{
	virtual void Add(int a, int b) = 0;
	virtual void Sub(int a, int b) = 0;
	virtual ~ICalc() {}
};

class Calc : public ICalc
{
	int server;
public:
	Calc() { server = ec_find_server("Calc"); }

	int Add(int a, int b) { return ec_send_server(server, 1, a, b); }
	int Sub(int a, int b) { return ec_send_server(server, 2, a, b); }
};
int main()
{
	Calc* pCalc = new Calc;

	int n1 = pCalc->Add(10, 20);
	int n2 = pCalc->Sub(10, 20);

	std::cout << n1 << ", " << n2 << std::endl;

}





