#include <iostream>

int main()
{
	// ���ڿ� �迭 vs ���ڿ� ������
	char sa[]      = "hello"; // ���ڿ��� "����"��
	const char* sp = "hello"; // ���ڿ��� "��� �޸𸮿�"
//	char* sp = "hello"; // C���� ���ڵ带 ���������
//	*sp = 'A'; // �̼��� runtime eror.. ��� �޸𸮴� ���� ����.

	//-----------------------

	char sa1[] = "hello";
	char sa2[] = "hello";

	const char* sp1 = "hello";
	const char* sp2 = "hello";

	printf("%p, %p\n", sp1, sp2);
}