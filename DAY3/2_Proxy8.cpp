#define USING_GUI
#include "cppmaster.h"
#include "ICalc.h"

// ��������� �ڵ����� �����ϴ� ����Ʈ �����͸� �����ϸ� 
// ���մϴ�.
template<typename T> class AutoPtr
{
	T* obj;
public:
	AutoPtr(T* p = nullptr) : obj(p) {}

	AutoPtr(const AutoPtr& ap) : obj(ap.obj) {}
	~AutoPtr() { }

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
	ICalc* p1 = ReloadProxy();
	p1->AddRef();	

	ICalc* p2 = p1;
	p2->AddRef();	

	p2->Release();
	std::cout << "------------------" << std::endl;
	p1->Release(); 

}





