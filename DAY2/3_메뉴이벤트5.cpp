// 3_�޴��̺�Ʈ5
#include <iostream>
#include <functional>

void foo(int a, int b, int c, int d)
{
	printf("%d, %d, %d, %d\n", a, b, c, d);
}

int main()
{
	foo(1, 2, 3, 4); // 4���Լ�

	// std::bind : M ���Լ��� �Ϻ� ���ڸ� �����ؼ� N ���Լ��� ����� ����
	//			  (��, M > N)
	//            �Լ�������� "currying ���"�� ������ ����!
	std::bind(&foo, 1, 2, 3, 4)();
}