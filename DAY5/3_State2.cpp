#include <iostream>

// 방법 1. 상태에 따라 분기문을 작성.
// => 새로운 상태(새로운 아이템)이 등장하면
//    모든 동작 함수의 코드가 수정되어야 한다. 
// => 좋지 않은 코드
class Charater
{
	int gold;
	int item;
public:
	void run() 
	{ 
		if (item == 1)
			std::cout << "run" << std::endl; 
		else if ( item == 2 )
			std::cout << "fast run" << std::endl;
	}
	void attack() 
	{ 
		if ( item == 1)
			std::cout << "attack" << std::endl; 
		else if ( item == 2 )
			std::cout << "power attack" << std::endl;
	}
};

int main()
{
	Charater* p = new Charater;
	p->run();
	p->attack();
}



