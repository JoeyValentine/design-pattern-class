#include <iostream>

// �����ۿ� ���� ĳ������ ������ ���������, ���´� �����Ǿ�� �Ѵ�.
// ���ϴ� ������ �������̽��� ����

struct IAction
{
	virtual void run() = 0;
	virtual void attack() = 0;
	virtual ~IAction() {}
	// jump(), slide() ���� ��� ������ �������̽���!
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
// �����ۿ� ���� ĳ������ ������ ������ ���� ��ü��..
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
	p->set_state(&ni); // ������ ȹ�� ����
	p->run();
	p->attack();

	p->set_state(&si); // ������ ȹ��.!!
						// ��ü�� ���¸� ����������
						// ��� �Լ��� ��ü �ȴ�.
						// ��ġ �ٸ� Ŭ������ ����ϴ°� ó�� ���δ�.
	p->run();
	p->attack();
}

// ���ϴ� ���� �и��ϱ� ����
// �������̽��� ���� ���ϴ� ���� �ٸ� Ŭ�������� �����ϴ� ������
// 3���� �� �ֽ��ϴ�.

// strategy : ��ü�� ����ϴ� "�˰���(��å)"�� ��ü - 185
// 
// state	: ��ü�� ���¿� ���� ������ ��ü(��κ��Ǹ���Լ��� ��ü)
//			  ��ġ �ٸ� Ŭ������ ����ϴ°� ó�� ����.
// 
// builder : ������ ��ü�� ���鶧, ��ü�� �����ϴ� �����
//							   ǥ���ϴ� ����� �и��ؼ� ��ü�� ����!

