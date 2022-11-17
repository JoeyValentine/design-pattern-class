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










template<typename T> struct slist
{
	Node<T>* head = 0;
public:
	void push_front(const T& a) { head = new Node<T>(a, head); }
};

int main()
{
	slist<int> s;
	s.push_front(10);
	s.push_front(20);
	s.push_front(30);
	s.push_front(40); 
}