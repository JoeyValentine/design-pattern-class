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

	// + �����ڿ� ���ؼ� �� ������ ���ô�.
	for (int i = 0; i < 5; i++)
	{
		int n1 = *(sp + i);
		int n2 = *(vp + i);
	}

}



