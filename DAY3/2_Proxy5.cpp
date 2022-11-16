#define USING_GUI
#include "cppmaster.h"
#include "ICalc.h"

// DLL 을 load 해서 Proxy 객체를 생성하는 함수
ICalc* ReloadProxy()
{
	// 1. 약속된 이름의 동적모듈을 load 합니다.
	void* addr = ec_load_module("CalcProxy.dll");
						// linux   : dlopen()
						// windows : LoadLibrary()

	// 2. 동적 모듈 내에서 약속된 함수 찾기
	typedef ICalc* (*F)(); // 함수 포인터를 저장하는 타입

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





