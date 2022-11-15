// 2_메뉴1.cpp  - 55 page
#include <iostream>

// C 언어로 구현한 메뉴소스 
// 장점 : 이해하기 쉽다. 간단하다.!
// 단점 : 메뉴가 추가되면 여러곳이 수정되어야 한다.
//       하위 메뉴가 존재하면 코드가 복잡해 질수 있다.

// 요구 사항(변화)에 유연하게 대응할수 없다.!!

int main()
{
	printf("1. 김밥\n");
	printf("2. 라면\n");
	printf("메뉴를 선택하세요 >> ");

	int cmd;
	std::cin >> cmd;

	switch (cmd)
	{
	case 1: break;
	case 2: break;
	}

}


