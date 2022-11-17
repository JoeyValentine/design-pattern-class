#include <iostream>

template<typename T> struct Node
{
	T     data;
	Node* next;
	Node(const T& d, Node* n) : data(d), next(n) {}
};

// 1. 모든 반복자가 지켜야 하는 규칙
// java           : iterator
// C#, 타이젠(C++) : Enumerator
template<typename T> struct iterator
{
	virtual T& next() = 0;
	virtual bool hasNext() = 0;
	virtual ~iterator() {}
};

// 2. 모든 컨테이너에서는 반복자는 꺼낼수 있어야 한다.
// => 컨테이너가 지켜야 하는 규칙
// java           : iterable
// C#, 타이젠(C++) : Enumerable
template<typename T> struct iterable
{
	virtual iterator<T>* iterator() = 0;
};

//======================
// 아래 코드가 slist 의 반복자 입니다. - 어렵지 않습니다...
template<typename T> 
class slist_iterator : public iterator<T>
{
	Node<T>* current = nullptr;
public:
	slist_iterator(Node<T>* p = nullptr) : current(p) {}

	// 2개 함수가 반드시 있어야 한다.
	virtual bool hasNext() 
	{
		return current != nullptr; 
	}

	virtual T& next()
	{
		T& ret = current->data;
		current = current->next;
		return ret;
	}
};
// slist_iterator<int> p(400번지);


template<typename T> struct slist : public iterable<T>
{
	Node<T>* head = 0;
public:
	void push_front(const T& a) { head = new Node<T>(a, head); }

	virtual iterator<T>* iterator() override
	{
		return new slist_iterator<T>(head);
	}
};

int main()
{
	slist<int> s;
	s.push_front(10);
	s.push_front(20);
	s.push_front(30);
	s.push_front(40); 

	iterator<int>* p = s.iterator();

	while (p->hasNext())
	{
		std::cout << p->next() << std::endl;
	}
}



