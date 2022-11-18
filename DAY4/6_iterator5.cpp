#include <iostream>
#include <list> // C++ ǥ�� ��������Ʈ
#include <forward_list> // �̱۸���Ʈ
#include <vector>		// ���ӵ� �޸��� �����̳�

int main()
{
	// �ٽ� 1. C++ ǥ�� �ݺ��� ����ϱ�
	std::list<int> ss = { 1,2,3,4,5 };

	auto p1 = ss.begin();	// 1��° ��Ҹ� ����Ű�� �ݺ���
	auto p2 = ss.end();		// ������ ����(��� ��ȸ�� ���� ���޿��� Ȯ���� ����)

	// p1 �� raw pointer �� �ƴմϴ�.
	// �׷���, ������ ó�� ����Ҽ� �ְ� �ϱ����� "������ ������" �Ǿ� �ֽ��ϴ�.

	while (p1 != p2)
	{
		std::cout << *p << std::endl;
		//++p1;
		p1.operator++(); // p1.next()
	}
}