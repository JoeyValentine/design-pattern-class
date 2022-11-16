#define USING_GUI
#include "cppmaster.h"

// 서버의 역활을 대신하는 클래스를 설계해 봅시다.

// proxy 패턴 : 기존 요소의 대행자를 만드는 패턴
// remote proxy : 원격지 서버를 대신하는 객체
// => 대행자를 통해서 다양한 기능을 추가할수 있다.
// => 인증된 사용자인지 조사
// => 자주 사용되는 연산에 대한 "캐쉬" 기능

// proxy : "함수 호출(Add)" 를 명령코드 "1" 로 변경해서 서버에 전달
// stub  : 도착한 명령코드 "1"을 다시 함수 호출(Server.Add())로변경


class Calc
{
	int server;
public:
	Calc() { server = ec_find_server("Calc"); }

	int Add(int a, int b) { return ec_send_server(server, 1, a, b);}
	int Sub(int a, int b) { return ec_send_server(server, 2, a, b);}
};
int main()
{
	Calc* pCalc = new Calc;

	int n1 = pCalc->Add(10, 20);
	int n2 = pCalc->Sub(10, 20);
		
	std::cout << n1 << ", " << n2 << std::endl;

}





