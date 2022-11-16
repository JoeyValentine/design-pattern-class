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
	ICalc* p1 = ReloadProxy();
	p1->AddRef();	// 규칙 1. Proxy 객체를 생성하면 참조계수 증기

	ICalc* p2 = p1;	
	p2->AddRef();	// 규칙 2. 포인터를 복사하면 참조계수 증가

	// 규칙 3. 포인터 사용후에는 참조 계수 감소
	p2->Release();
	std::cout << "------------------" << std::endl;
	p1->Release(); // 이순간 객체가 파괴 됩니다.
}





