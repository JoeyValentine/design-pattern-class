#define USING_GUI
#include "cppmaster.h"

// �ᱹ �� �ڵ�� "�ٸ� ���μ����� �Լ��� ȣ��" �ϰ� �ֽ��ϴ�.

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

// �� Proxy Ŭ������ ���� ����� ���ϱ�� ?
// 1. Server ������  => ����!!
// 2. Client ������

int main()
{
	// �Ʒ� �ڵ�� Client �� Proxy ����
	// ���� ����(Proxy Ŭ���� �̸��� ���� ���) �Դϴ�.
	// ���ο� Proxy �� ������ �ڵ尡 �����Ǿ�� �մϴ�.
	// ��ü �Ұ����� ������ ������ �Դϴ�.
	// Calc* pCalc = new Calc;

	// ��ü ������ ������ �������� �Ƿ��� ���� ����(�������̽�)�� ����ؾ��մϴ�.
	ICalc* pCalc = new ICalc ; // error.
								// �������̽��� ��ü�����Ҽ��� �����ϴ�.!

	int n1 = pCalc->Add(10, 20);
	int n2 = pCalc->Sub(10, 20);

	std::cout << n1 << ", " << n2 << std::endl;

}





