#define USING_GUI
#include "cppmaster.h"

// ������ ��Ȱ�� ����ϴ� Ŭ������ ������ ���ô�.
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





