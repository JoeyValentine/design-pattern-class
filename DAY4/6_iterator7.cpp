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

	// 연속된 메모리를 사용하는 컨테이너의 반복자는 + 연산이 되고
	// 연속되지 않은 메모리를 사용하는 컨테이너의 반복자는 + 연산은 안되고 ++만됩니다.
//	sp = sp + 1; // error
	vp = vp + 1; // ok

	// 이유는 list 에 + 연산을 제공하면 아래 코드와 같은 실수를 하게 됩니다.
	// + 연산자에 대해서 잘 생각해 봅시다.
	for (int i = 0; i < 5; i++)
	{
		int n1 = *(sp + i); // <=== 너무 느린 코드 입니다. 최악의 코드입니다.
		int n2 = *(vp + i);
	}

	// 그럼 list 의 반복자는 3칸이동하려면 어떻게 하나요 ?
	std::advance(sp, 3); // ++sp 

}



