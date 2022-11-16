// CalcProxy.cpp
#define USING_GUI
#include "cppmaster.h"
#include "ICalc.h"

class Calc : public ICalc
{
	int server;
public:
	Calc() { server = ec_find_server("Calc"); }

	int Add(int a, int b) { return ec_send_server(server, 1, a, b); }
	int Sub(int a, int b) { return ec_send_server(server, 2, a, b); }
};

// ��������� ����ϴ� client �� ���� ��⳻�� proxy Ŭ���� �̸���
// ������ ���ϰ�, ���ʿ䵵 ����, �˾Ƶ� �ȵ˴ϴ�.
// => ���� ��� ���ο��� Proxy ��ü�� ������ �����ؾ� �մϴ�.
extern "C" __declspec(dllexport)
ICalc* Create()
{
	return new Calc;
}
//===============================
// ���� �ϴ� ��
// => ������ ���� ��ư => Visual Studio ���� ����
// => ������ ��� ������Ʈ ����(comand prompt for developer)
// => �ҽ��� �ִ� ������ �̵���
// 
// cl CalcProxy.cpp /LD /link user32.lib gdi32.lib kernel32.lib

// D:      => D ����̺� �̵�
// cd ����  => ������ �̵�
// cd ..   => ���� �����̵�.


