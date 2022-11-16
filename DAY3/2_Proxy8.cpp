#define USING_GUI
#include "cppmaster.h"
#include "ICalc.h"

// 참조계수를 자동으로 관리하는 스마트 포인터를 도입하면 
// 편리합니다.
template<typename T> class AutoPtr
{
	T* obj;
public:
	AutoPtr(T* p = nullptr) : obj(p) 
	{
		if (obj) obj->AddRef();
	}

	AutoPtr(const AutoPtr& ap) : obj(ap.obj) 
	{
		if (obj) obj->AddRef();
	}
	~AutoPtr() 
	{
		if (obj) obj->Release();
	}
	// 스마트 포인터는 객체지만 ->, * 연산자 재정의를 통해서
	// 포인터 처럼 사용가능하게 합니다.
	T* operator->() { return obj; }
	T& operator*()  { return *obj; }
};





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
	AutoPtr<ICalc> p1( ReloadProxy() );	// 생성자 
	AutoPtr<ICalc> p2 = p1;				// 복사 생성자

	int n1 = p1->Add(10, 20);
	int n2 = p1->Sub(10, 20);

	std::cout << n1 << ", " << n2 << std::endl;
}


/*
int main()
{
	ICalc* p1 = ReloadProxy();
	p1->AddRef();	

	ICalc* p2 = p1;
	p2->AddRef();	

	p2->Release();
	std::cout << "------------------" << std::endl;
	p1->Release(); 

}
*/


// java, C# : garbage collector 사용
//			=> 사용되지 않은 객체를 즉시 삭제 하지는 않음
//			=> 메모리가 부족할때만 사용하지 않은 객체 제거
//			=> 소멸자(finalizer) 의 호출시점이 명확하지 않음

// python, swift : reference counting 사용
//			=> 참조계수가 0이면 즉시 파괴
//			=> 소멸자 호출이 명확함.

// 파이썬
//n1 = 10;
//n2 = n1;

