#include <iostream>

// 아이템에 따라 캐릭터의 동작은 변경되지만, 상태는 유지되어야 한다.
// 변하는 동작을 인터페이스로 설계

struct IAction
{
	virtual void run() = 0;
	virtual void attack() = 0;
	virtual ~IAction() {}
	// jump(), slide() 등의 모든 동작을 인터페이스로!
};

class Charater
{
	int gold;
	int item;
	IAction* paction = nullptr;
public:
	void set_state(IAction* p) { paction = p; }

	void run()    { paction->run(); }
	void attack() { paction->attack(); }
};
// 아이템에 따라 캐릭터의 동작을 정의한 동작 객체들..
class NoItem : public IAction
{
public:
	virtual void run() { std::cout << "run" << std::endl; }
	virtual void attack() { std::cout << "attack" << std::endl; }
};
class RedItem : public IAction
{
public:
	virtual void run() { std::cout << "run" << std::endl; }
	virtual void attack() { std::cout << "power attack" << std::endl; }
};

class StarItem : public IAction
{
public:
	virtual void run() { std::cout << "fast run" << std::endl; }
	virtual void attack() { std::cout << "power attack" << std::endl; }
};


int main()
{
	NoItem ni;
	RedItem ri;
	StarItem si;
	Charater* p = new Charater;
	p->set_state(&ni); // 아이템 획득 안함
	p->run();
	p->attack();

	p->set_state(&si); // 아이템 획득.!!
						// 객체는 상태를 유지하지만
						// 멤버 함수가 교체 된다.
						// 마치 다른 클래스를 사용하는것 처럼 보인다.
	p->run();
	p->attack();
}



