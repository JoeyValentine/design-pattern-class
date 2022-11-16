#define USING_GUI
#include "cppmaster.h"
#include "ICalc.h"

// DLL �� load �ؼ� Proxy ��ü�� �����ϴ� �Լ�
ICalc* ReloadProxy()
{
	// 1. ��ӵ� �̸��� ��������� load �մϴ�.
	void* addr = ec_load_module("CalcProxy.dll");
						// linux   : dlopen()
						// windows : LoadLibrary()

	// 2. ���� ��� ������ ��ӵ� �Լ� ã��
	typedef ICalc* (*F)(); // �Լ� �����͸� �����ϴ� Ÿ��

	F f = (F)ec_get_function_address(addr, "Create");
						// linux   : dlsym()
						// windows : GetProcAddress()

	ICalc* p = f();
	return p;
}

int main()
{
	ICalc* pCalc = ReloadProxy();	

	int n1 = pCalc->Add(10, 20);
	int n2 = pCalc->Sub(10, 20);

	std::cout << n1 << ", " << n2 << std::endl;

}





