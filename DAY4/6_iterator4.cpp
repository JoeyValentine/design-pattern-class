#include <iostream>


// C++�� ����ϸ�
// 1. s.iterator() �� ��� �ݺ��ڴ� "new �� �Ҵ�Ȱ�"
//    => ����Ŀ� delete �ؾ� �Ѵ�.

// 2. �������� �̵��ϴ� �Լ� "next()" �� �����Լ��̴�.
//    => ������. �����̽�!

// 3. ������ ������� ���� �ϱ�� �ߴµ�..
//    "raw array" ���� ��İ� �ٸ���!!
/*
int arr[5] = { 1,2,3,4,5 };
int* p = arr;

while (p != arr + 5)
{
	std::cout << *p << std::endl;
	++p;
}
*/



template<typename T> struct Node
{
	T     data;
	Node* next;
	Node(const T& d, Node* n) : data(d), next(n) {}
};

//======================
// �Ʒ� �ڵ尡 slist �� �ݺ��� �Դϴ�. - ����� �ʽ��ϴ�...
template<typename T>
class slist_iterator 
{
	Node<T>* current = nullptr;
public:
	slist_iterator(Node<T>* p = nullptr) : current(p) {}

	inline slist_iterator& operator++()
	{
		current = current->next;
		return *this;
	}
	inline T& operator*() { return current->data; }
};

// slist_iterator<int> p(400����);
// ++p;  �� �̵�			=> p.operator++()
// int n = *p; �� ����	=> p.operator*()


template<typename T> struct slist 
{
	Node<T>* head = 0;
public:
	void push_front(const T& a) { head = new Node<T>(a, head); }
	
	inline slist_iterator<T> begin()
	{
		return slist_iterator<T>(head); // new �ƴ�.
	}
};

int main()
{
	slist<int> s;
	s.push_front(10);
	s.push_front(20);
	s.push_front(30);
	s.push_front(40);
	
	slist_iterator<int> p = s.begin();

	// p�� �����ʹ� �ƴ�����, ������ ó�� �����ϰ� ����ϸ� �˴ϴ�.
	std::cout << *p << std::endl;
	++p;
	std::cout << *p << std::endl;
}


