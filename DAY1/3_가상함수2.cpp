#include <iostream>

// java, C# : "garbage collector" �� �ֽ��ϴ�.
//            �� �޸� �������� �۾��� ���� �մϴ�.
//			  �Ҹ���(finalizer) �� ���������� ���� �����ϴ�.

// C++ : ����ڰ� �ڿ������ؾ� �մϴ�.
//       �Ҹ��ڰ� ���� �߿� �մϴ�.
// �ٽ� 1. ��� ��� Ŭ������ �Ҹ��ڴ� �ݵ�� �����Լ��� ������ �մϴ�.
//     2. ��� Ŭ������ �Ҹ��ڰ� �����Լ� ��� ��� �Ļ� Ŭ������ �Ҹ��ڵ�
//        virtual �Դϴ�.(virtual �� ������ �ʾƵ�)
class Base
{
public:
	virtual ~Base() { std::cout << "~Base" << std::endl; }
};
class Derived : public Base
{
public:
	Derived()  { std::cout << "Derived() �ڿ��Ҵ�" << std::endl; }
	~Derived() { std::cout << "~Derived() �ڿ�����" << std::endl; }
};
class Derived2: public Derived
{
public:
	Derived2() { std::cout << "Derived2() �ڿ��Ҵ�" << std::endl; }
	~Derived2() { std::cout << "~Derived2() �ڿ�����" << std::endl; }
};
int main()
{
//	Derived d;

//	Derived* p = new Derived; // ������ ȣ��
//	delete p;  // �̼��� ��ü�� �ı� �ǹǷ� �Ҹ��� ȣ��


	Base* p = new Derived2; // ������ ȣ��

	delete p; // �̼��� �Ҹ��ڸ� ȣ���ؾ� �ϴµ�
			  // ������ �Ҷ� ȣ���� ��������, �����Ҷ� ���� ���ؾ��մϴ�.
			  // 
			// 1. p�� Base* Ÿ���̹Ƿ� Base Ŭ������ �����ؼ�
			//    �Ҹ��ڰ� �����Լ� ���� ����
			// �����Լ��� �ƴϸ� : ������ Base �Ҹ��� ȣ��
			// �����Լ����     : �����Ҷ� �޸� ������ ����
}	




