#define USING_GUI
#include "cppmaster.h"

// ������ ��Ȱ�� ����ϴ� Ŭ������ ������ ���ô�.

// proxy ���� : ���� ����� �����ڸ� ����� ����
// remote proxy : ������ ������ ����ϴ� ��ü
// => �����ڸ� ���ؼ� �پ��� ����� �߰��Ҽ� �ִ�.
// => ������ ��������� ����
// => ���� ���Ǵ� ���꿡 ���� "ĳ��" ���

// proxy : "�Լ� ȣ��(Add)" �� ����ڵ� "1" �� �����ؼ� ������ ����
// stub  : ������ ����ڵ� "1"�� �ٽ� �Լ� ȣ��(Server.Add())�κ���


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





