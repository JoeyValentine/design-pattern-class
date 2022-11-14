#include <iostream>

// �ٽ� 1. �Լ� override

class Animal
{
public:
	// �Լ� ȣ���� ������ �ð��� ������ �޶�
	void cry1() { std::cout << "Animal Cry1" << std::endl; } 

	// virtual function : �Լ� ȣ���� ���� �ð��� ������ �޶�
	virtual void cry2() { std::cout << "Animal Cry2" << std::endl; }
};
class Dog : public Animal
{
public:
	void cry1() { std::cout << "Dog Cry1" << std::endl; } 

	virtual void cry2() { std::cout << "Dog Cry2" << std::endl; }
};


int main()
{
	Dog d;
	Animal* p = &d; 

	// C++, C#				       : Animal Cry1
	// java, python, swift, kotlin : Dog Cry1

	// ��� �Լ��� ȣ�������� ���� �����Ұ��ΰ��� ���� �޶����ϴ�.
	// 1. ������ �ð��� ����		 : ������
	//							   ���� : ������ ������ Ÿ�����θ� ����
	//									 Animal Cry1()
	// 2. �����Ҷ� �޸� ������ ���� : ������. 
	//								���� : p�� ����Ű�� ��ü�� ������ ȣ��
	//									  Dog Cry1() ȣ��
		
	p->cry1(); // Animal Cry1
	p->cry2(); // Dog    Cry2
}


