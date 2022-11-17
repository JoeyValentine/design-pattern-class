#include <iostream>

template<typename T> struct Node
{
	T     data;
	Node* next;
	Node(const T& d, Node* n) : data(d), next(n) {}
};

// 1. ��� �ݺ��ڰ� ���Ѿ� �ϴ� ��Ģ
// java           : iterator
// C#, Ÿ����(C++) : Enumerator
template<typename T> struct iterator
{
	virtual T& next() = 0;
	virtual bool hasNext() = 0;
	virtual ~iterator() {}
};

// 2. ��� �����̳ʿ����� �ݺ��ڴ� ������ �־�� �Ѵ�.
// => �����̳ʰ� ���Ѿ� �ϴ� ��Ģ
// java           : iterable
// C#, Ÿ����(C++) : Enumerable
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