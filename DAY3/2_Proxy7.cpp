#define USING_GUI
#include "cppmaster.h"
#include "ICalc.h"

ICalc* ReloadProxy()
{
	void* addr = ec_load_module("CalcProxy.dll");
	typedef ICalc* (*F)();

	F f = (F)ec_get_function_address(addr, "Create");

	ICalc* p = f(); // DLL �ȿ��� "new Calc"
	return p;
}

int main()
{
	ICalc* p1 = ReloadProxy();
	p1->AddRef();	// ��Ģ 1. Proxy ��ü�� �����ϸ� ������� ����

	ICalc* p2 = p1;	
	p2->AddRef();	// ��Ģ 2. �����͸� �����ϸ� ������� ����

	// ��Ģ 3. ������ ����Ŀ��� ���� ��� ����
	p2->Release();
	std::cout << "------------------" << std::endl;
	p1->Release(); // �̼��� ��ü�� �ı� �˴ϴ�.
}





