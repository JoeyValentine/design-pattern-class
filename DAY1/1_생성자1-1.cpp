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
	// �ٽ� 1 : ��� Ŭ������ ����Ʈ �����ڰ� ������ �Ʒ� 2���� �����Դϴ�.
//	Derived()     {}  // Derived()      : Base() {}
//	Derived(int a){}  // Derived(int a) : Base(){}

	// �ٽ� 2 : ��� Ŭ������ ����Ʈ �����ڰ� ���ٸ�
	// => �ݵ�� �Ļ� Ŭ������ ���鶧 ��� Ŭ������ �����ڸ� ���������
	//    ȣ���ؾ� �մϴ�.
	Derived()     : Base(0) {}  
	Derived(int a): Base(a) {}
};

int main()
{
	Derived d1;
	Derived d2(5);
}

