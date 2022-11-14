#include <iostream>
// �ٽ� : ������ ȣ���� ��Ȯ�� ����!
class Base
{
public:
	Base() { std::cout << "Base()" << std::endl; }
	Base(int a){ std::cout << "Base(int)" << std::endl; }
	~Base()    { std::cout << "~Base()" << std::endl; }
};
class Derived : public Base
{
public:	
	// ������ڵ�			// �����Ϸ��� ������ �ڵ�
	Derived()			// Derived() : Base() 
	{ 
		std::cout << "Derived()" << std::endl; 
	}
						// �ٽ� : �����Ϸ� ���� �ڵ�� �׻�
						//		 ��� Ŭ������ ����Ʈ ������ ȣ��
	Derived(int a)		// Derived(int a) : Base() 
	{ 
		std::cout << "Derived(int)" << std::endl; 
	}
	~Derived()		
	{
		std::cout << "~Derived()" << std::endl; 

		// �Ҹ��ڴ� ����ڰ� ���� �ڵ带 ���������ϰ� �ϰ�
		// �����Ϸ��� �Ʒ� �ڵ� �߰�
		// ~Base();
	}
};
int main()
{
//	Derived d1;		// call Derived::Derived()
	Derived d2(5);  // call Derived::Derived(5)

}

