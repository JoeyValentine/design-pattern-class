#include <iostream>
#include <vector>
#include <allocators> // C++ ǥ�� �޸� �Ҵ��

int main()
{
	// C/C++ ���� �޸𸮸� �Ҵ�/���� �ϴ� ���� ����� �ֽ��ϴ�
	// => new, delete
	// => malloc, free
	// => linux system call, windows win32 api
	// => �޸� Ǯ��

	// �޸� �Ҵ� ���
	// 1. new / delete �� ���� ���
	// => ���� �޸� �Ҵ� ����� �����Ѵٸ�
	// => �Ʒ� �ڵ� ��ü�� �����ؾ� �մϴ�.
	int* p1 = new int[10];
	delete[] p1;

	int* p2 = new int[10];
	delete[] p2;


	// 2. allocator ���
	// => �޸� �Ҵ�/���� ��å�� ���� Ŭ����
	std::allocator<int> ax;  // ǥ�� �Ҵ�� - new / delete ���


	int* p = ax.allocate(10); // ǥ�� �Ҵ���� "new int[10]"

	ax.deallocate(p, 10);	// ǥ�� �Ҵ���� "delete[] p"

}