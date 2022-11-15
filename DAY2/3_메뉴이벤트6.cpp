// 3_�޴��̺�Ʈ5
#include <iostream>
#include <functional>
using namespace std::placeholders; // _1, _2, _3....

void foo(int a, int b, int c, int d)
{
	printf("%d, %d, %d, %d\n", a, b, c, d);
}
void f1(int a)               { printf("f1\n"); }
void f3(int a, int b, int c) { printf("f3\n"); }

class Dialog
{
public:
	void close(int a, int b) { std::cout << "Camera close" << std::endl; }
};

int main()
{	
	// C�� �Լ������ʹ� �������� �����մϴ�.
//	void(*f)(int) = &f1; //ok
//	f = &f3; // error


	// C++11 �� "std::function" �� �Լ� �����͸� �Ϲ�ȭ��
	// Ŭ���� ���ø� �Դϴ�. - �������� �����ϴ�.

	std::function<void(int)> f;

	f = &f1;
	f(10); // ok. f1(10);

	//-------------------------------------
//	f = &f3; // error. f3�� ���ڰ� 3�� �Դϴ�.

	// �ٽ� : function �� bind ����� ������ ���ο� �Լ��� �����Ҽ� �ֽ��ϴ�
	
	f = std::bind(&f3, 3, _1, 8);
	f(2); // f3(3, 2, 8);


	// ��� �Լ��� "��ü"�� �����ؾ� �մϴ�.
	Dialog dlg;
	f = std::bind(&Dialog::close, &dlg, 3, _1);
	f(9); // dlg.close(3, 9);


	// ��� : std::bind ���п� std::function �� ��ü�� �� f ����
	//       ���ڰ� �Ѱ� �̻��� ��� ������ �Լ�, ��� �Լ�, 
	//       static ����Լ�, ���� ǥ���ĵ��� ���� ���������մϴ�.
}