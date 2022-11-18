#include <iostream>

// ��� 2. ���ؾ� �ϴ� ������ "�����Լ���"
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

	p = new StarItem;	// ������ ȹ�� �� �ƴ�.!
						// => ���� ĳ������ ���� ������ �ƴ�
						// => ������ ����� ���ο� ĳ����

						// => �츮�� �ʿ��Ѱ��� 
						//		"���´� �����Ǹ鼭 ���۸� ����"
						
	p->run();
	p->attack();
}



