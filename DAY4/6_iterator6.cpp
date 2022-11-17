#include <iostream>
#include <list> // C++ ǥ�� ������Ʈ
#include <forward_list> // �̱۸���Ʈ
#include <vector>		// ���ӵ� �޸��� �����̳�

int main()
{
	std::list<int> ds = { 1,2,3,4,5 }; // ���� ��ũ�� ����Ʈ
	std::forward_list<int> fs = { 1,2,3,4,5 }; // �̱� ��ũ�� ����Ʈ

	auto p1 = ds.begin();
	auto p2 = fs.begin();

	// ������ ������ ã������
	++p1;	
	++p2;
	--p1;
	--p2;
}