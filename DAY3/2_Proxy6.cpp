#define USING_GUI
#include "cppmaster.h"
#include "ICalc.h"

ICalc* ReloadProxy()
{
	void* addr = ec_load_module("CalcProxy.dll");
	typedef ICalc* (*F)(); 

	F f = (F)ec_get_function_address(addr, "Create");

	ICalc* p = f(); // DLL 안에서 "new Calc"
	return p;
}

int main()
{
	ICalc* pCalc = ReloadProxy();

	int n1 = pCalc->Add(10, 20);
	int n2 = pCalc->Sub(10, 20);

	std::cout << n1 << ", " << n2 << std::endl;

//	delete pCalc; // 좋은 코드일까요 ?
				  // 동적 모듈 내에서 할당한 자원(메모리)를
				  // 실행파일에서 해지 하는 것은 바람직하지 않습니다.
}





