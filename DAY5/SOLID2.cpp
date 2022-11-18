// LSP : Liskov Substitution Principle
//		=> 파생 클래스는 기반 클래스를 대체 할수 있어야 한다.

#include <list>

class LinkedList
{
public:
	virtual void push_front(int a) {}
	virtual void push_back(int a) {}
};

// 아래 함수는 LinkedList 뿐 아니라
// LinkedList 의 파생 클래스도 전달가능해야 합니다.
void foo(LinkedList* p) 
{
	p->push_back(10);
	p->push_front(10);
}

class stack : public LinkedList
{
public:
	void push(int a) { LinkedList::push_back(a); }

	void push_front(int a) { throw 1; }
	void push_back(int a) { throw 1; }
};

int main()
{
	stack s;
	foo(&s);
}