#define USING_GUI
#include "cppmaster.h"
#include "ICalc.h"

// ��������� �ڵ����� �����ϴ� ����Ʈ �����͸� �����ϸ� 
// ���մϴ�.
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
	// ����Ʈ �����ʹ� ��ü���� ->, * ������ �����Ǹ� ���ؼ�
	// ������ ó�� ��밡���ϰ� �մϴ�.
	T* operator->() { return obj; }
	T& operator*()  { return *obj; }
};





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
	AutoPtr<ICalc> p1( ReloadProxy() );	// ������ 
	AutoPtr<ICalc> p2 = p1;				// ���� ������

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




