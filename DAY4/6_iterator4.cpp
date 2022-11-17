#include <iostream>


// C++언어를 고려하면
// 1. s.iterator() 로 얻는 반복자는 "new 로 할당된것"
//    => 사용후에 delete 해야 한다.

// 2. 다음으로 이동하는 함수 "next()" 가 가상함수이다.
//    => 느리다. 성능이슈!

// 3. 동일한 방법으로 열거 하기로 했는데..
//    "raw array" 열거 방식과 다르다!!
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
// 아래 코드가 slist 의 반복자 입니다. - 어렵지 않습니다...
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

// slist_iterator<int> p(400번지);
// ++p;  로 이동			=> p.operator++()
// int n = *p; 로 접근	=> p.operator*()


template<typename T> struct slist 
{
	Node<T>* head = 0;
public:
	void push_front(const T& a) { head = new Node<T>(a, head); }
	
	inline slist_iterator<T> begin()
	{
		return slist_iterator<T>(head); // new 아님.
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

	// p는 포인터는 아니지만, 포인터 처럼 생각하고 사용하면 됩니다.
	std::cout << *p << std::endl;
	++p;
	std::cout << *p << std::endl;
}


