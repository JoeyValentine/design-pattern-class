#define USING_GUI
#include "cppmaster.h"

// �ᱹ �� �ڵ�� "�ٸ� ���μ����� �Լ��� ȣ��" �ϰ� �ֽ��ϴ�.

// RPC : Remote Procedure Call
// RMI : Remote Method Invocation( java, C# )


// Proxy �� ������ ������ �̹Ƿ�
// ������ ������ ����� �����ϴ� ���� �����ϴ� ���� �����ϴ�.
// => �������̽��� ���� �մϴ�.
// => ������ Proxy �� ���鶧 ��� �Ʒ� �������̽��� �����ؾ� �մϴ�.
struct ICalc
{
	virtual int Add(int a, int b) = 0;
	virtual int Sub(int a, int b) = 0;
	virtual ~ICalc() {}
};

// ���� ���ο� ����� �߰��Ƿ���
// 1. �������̽��� �Լ� �߰�
// 2. Proxy �� �Լ� �߰�
// 3. Stub �� �߰��ϰ�, 
// 4. ������ ���� ��� �߰��ϸ� �˴ϴ�.

// �� 1, 2, 3 �� �ڵ����� �������ִ� �� "IDL" ��� �մϴ�.
// IDL : interface definition language


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




