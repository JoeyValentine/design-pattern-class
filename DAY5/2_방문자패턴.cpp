#include <iostream>
#include <list>
#include <vector>

// visitor ����
// 
// �ݺ���(iterator) : ���հ�ü�� ��� ��Ҹ� "������ ������� ����"
// �湮��(visitor)  : ���հ�ü�� ��� ��Ҹ� "������ ������� �������"


int main()
{
	std::list<int> s = { 1,2,3,4,5,6,7,8,9,10 };

	// ���հ�ü�� ��� ��ҿ� ������ �ϰ� ������!!
	
	// ��� 1. ���� ��� ��Ҹ� ��ȸ �ϸ鼭 �������
	// s�� ��� ��Ҹ� 2��� �ϰ� �ʹ�.
	for (auto& e : s)
		e *= 2;

	// s �� ��� ��Ҹ� ����ϰ� �ʹ�.
	for (auto& e : s)
		std::cout << e << ", ";
	std::cout << std::endl;


	// ��� 2. �湮�� ������ ����Ѵ�.
	TwiceVisitor<int> tv;	// ��� ��Ҹ� 2��� �ϴ� �湮��
	s.Accept(&tv);			

	ShowVisitor<int> sv;	// ��� ��Ҹ� ����ϴ� �湮��
	s.Accept(&sv);
}





