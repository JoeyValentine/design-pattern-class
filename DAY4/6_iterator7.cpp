#include <iostream>
#include <list>
#include <forward_list>
#include <vector>		

int main()
{
	std::list<int>   s = { 1,2,3,4,5 }; 
	std::vector<int> v = { 1,2,3,4,5 };

	auto sp = s.begin();
	auto vp = v.begin();

	// ���ӵ� �޸𸮸� ����ϴ� �����̳��� �ݺ��ڴ� + ������ �ǰ�
	// ���ӵ��� ���� �޸𸮸� ����ϴ� �����̳��� �ݺ��ڴ� + ������ �ȵǰ� ++���˴ϴ�.
//	sp = sp + 1; // error
	vp = vp + 1; // ok

	// ������ list �� + ������ �����ϸ� �Ʒ� �ڵ�� ���� �Ǽ��� �ϰ� �˴ϴ�.
	// + �����ڿ� ���ؼ� �� ������ ���ô�.
	for (int i = 0; i < 5; i++)
	{
		int n1 = *(sp + i); // <=== �ʹ� ���� �ڵ� �Դϴ�. �־��� �ڵ��Դϴ�.
		int n2 = *(vp + i);
	}

	// �׷� list �� �ݺ��ڴ� 3ĭ�̵��Ϸ��� ��� �ϳ��� ?
	std::advance(sp, 3); // ++sp 

}



