#include <iostream>

// java, C# : "garbage collector" �� �ֽ��ϴ�.
//            �� �޸� �������� �۾��� ���� �մϴ�.
//			  �Ҹ���(finalizer) �� ���������� ���� �����ϴ�.

// C++ : ����ڰ� �ڿ������ؾ� �մϴ�.
//       �Ҹ��ڰ� ���� �߿� �մϴ�.

class Base
{
public:
	~Base() {}
};
class Derived : public Base
{
public:
	Derived()  { std::cout << "Derived() �ڿ��Ҵ�" << std::endl; }
	~Derived() { std::cout << "~Derived() �ڿ�����" << std::endl; }
};
int main()
{
//	Derived d;

//	Derived* p = new Derived; // ������ ȣ��
//	delete p;  // �̼��� ��ü�� �ı� �ǹǷ� �Ҹ��� ȣ��


	Base* p = new Derived; // ������ ȣ��

	delete p; // �̼��� �Ҹ��ڸ� ȣ���ؾ� �ϴµ�
			  // ������ �Ҷ� ȣ���� ��������, �����Ҷ� ���� ���ؾ��մϴ�.
			  // 
			// 1. p�� Base* Ÿ���̹Ƿ� Base Ŭ������ �����ؼ�
			//    �Ҹ��ڰ� �����Լ� ���� ����
			// �����Լ��� �ƴϸ� : ������ Base �Ҹ��� ȣ��
			// �����Լ����     : �����Ҷ� �޸� ������ ����
}	




