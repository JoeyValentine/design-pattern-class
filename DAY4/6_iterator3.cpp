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

//======================
// �Ʒ� �ڵ尡 slist �� �ݺ��� �Դϴ�. - ����� �ʽ��ϴ�...
template<typename T> 
class slist_iterator : public iterator<T>
{
	Node<T>* current = nullptr;
public:
	slist_iterator(Node<T>* p = nullptr) : current(p) {}

	// 2�� �Լ��� �ݵ�� �־�� �Ѵ�.
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
// slist_iterator<int> p(400����);


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



