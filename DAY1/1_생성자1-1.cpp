// 1_������1-1.cpp    1�� �����ؿ�����
#include <iostream>
// �ٽ� : ��� Ŭ������ ����Ʈ �����ڰ� ������ !!
class Base
{
public:
//	Base() { std::cout << "Base()" << std::endl; }
	Base(int a) { std::cout << "Base(int)" << std::endl; }
	~Base() { std::cout << "~Base()" << std::endl; }
};
class Derived : public Base
{
public:
	Derived() {	}
	Derived(int a){}
};

int main()
{

}

