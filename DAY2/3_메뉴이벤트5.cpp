// 3_�޴��̺�Ʈ5
#include <iostream>
#include <functional>
using namespace std::placeholders; // _1, _2, _3....

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

	// ���� : std::bind( M���Լ��ּ�, M���� ����)

	std::bind(&foo, 1, 2, 3, 4)(); // 4���Լ� => 0�� �Լ���!
	//<---- ����� �ٽ� �Լ� --->|

	std::bind(&foo, 5, _1, 9, _2)(7, 3); // foo(5,7,9,3)
								// ��, 4�� => 2�� �Լ��� ����


	std::bind(&foo, _2, 8 , _3 , _1 )(7, 9, 2); // foo(9, 8, 2, 7)
								// 4�� �Լ��� 3���Լ��� �����Ѱ�

	// ���̽㿡�� ���� ���� ������ �ֽ��ϴ�. : functools.partial ã�ƺ�����
}