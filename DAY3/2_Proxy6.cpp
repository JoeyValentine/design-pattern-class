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
	ICalc* pCalc = ReloadProxy();

	int n1 = pCalc->Add(10, 20);
	int n2 = pCalc->Sub(10, 20);

	std::cout << n1 << ", " << n2 << std::endl;

//	delete pCalc; // ���� �ڵ��ϱ�� ?
				  // ���� ��� ������ �Ҵ��� �ڿ�(�޸�)��
				  // �������Ͽ��� ���� �ϴ� ���� �ٶ������� �ʽ��ϴ�.
}





