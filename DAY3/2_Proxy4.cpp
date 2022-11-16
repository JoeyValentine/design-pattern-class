#define USING_GUI
#include "cppmaster.h"

// 결국 이 코드는 "다른 프로세스의 함수를 호출" 하고 있습니다.

// RPC : Remote Procedure Call
// RMI : Remote Method Invocation( java, C# )


struct ICalc
{
	virtual int Add(int a, int b) = 0;
	virtual int Sub(int a, int b) = 0;
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

// 위 Proxy 클래스는 누가 만드는 것일까요 ?
// 1. Server 제작자  => 정답!!
// 2. Client 제작자

int main()
{
	// 아래 코드는 Client 와 Proxy 간에
	// 강한 결합(Proxy 클래스 이름을 직접 사용) 입니다.
	// 새로운 Proxy 가 나오면 코드가 수정되어야 합니다.
	// 교체 불가능한 경직된 디자인 입니다.
	// Calc* pCalc = new Calc;

	// 교체 가능한 유연한 디자인이 되려면 약한 결합(인터페이스)를 사용해야합니다.
	ICalc* pCalc = new ICalc ; // error.
								// 인터페이스를 객체생성할수는 없습니다.!

	int n1 = pCalc->Add(10, 20);
	int n2 = pCalc->Sub(10, 20);

	std::cout << n1 << ", " << n2 << std::endl;

}





