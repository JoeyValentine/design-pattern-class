// LSP : Liskov Substitution Principle
//		=> �Ļ� Ŭ������ ��� Ŭ������ ��ü �Ҽ� �־�� �Ѵ�.

#include <list>

class LinkedList
{
public:
	virtual void push_front(int a) {}
	virtual void push_back(int a) {}
};

// �Ʒ� �Լ��� LinkedList �� �ƴ϶�
// LinkedList �� �Ļ� Ŭ������ ���ް����ؾ� �մϴ�.
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