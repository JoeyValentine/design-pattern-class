#include <iostream>

// 방법 2. 변해야 하는 동작을 "가상함수로"
class Charater
{
	int gold;
	int item;
public:
	void run() { do_run(); }
	void attack() { do_attack(); }

	virtual void do_run()    { std::cout << "run" << std::endl; }
	virtual void do_attack() { std::cout << "attack" << std::endl; }
};

class StarItem : public Charater
{
public:
	virtual void do_run()   override { std::cout << "fast run" << std::endl; }
	virtual void do_attack()override { std::cout << "power attack" << std::endl; }
};

int main()
{
	Charater* p = new Charater;
	p->run();
	p->attack();

	p = new StarItem;	// 아이템 획득 이 아님.!
						// => 기존 캐릭터의 동작 변경이 아닌
						// => 동작이 변경된 새로운 캐릭터

						// => 우리가 필요한것은 
						//		"상태는 유지되면서 동작만 변경"
						
	p->run();
	p->attack();
}



