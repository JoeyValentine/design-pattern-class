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

// 우리는 slist 버전만 만들었지만
// vector 가 있다면 vector 도 위처럼 인터페이스를 구현해서 반복자만들면 됩니다.


// 위 코드가 "전통적인 객체지향 디자인 패턴의 반복자 형태" 입니다.
// Java, C#, Python, Swift 등.. 

// C++언어를 고려하면
// 1. s.iterator() 로 얻는 반복자는 "new 로 할당된것"
//    => 사용후에 delete 해야 한다.

// 2. 다음으로 이동하는 함수 "next()" 가 가상함수이다.
//    => 느리다. 성능이슈!

// 3. 동일한 방법으로 열거 하기로 했는데..
//    "raw array" 열거 방식과 다르다!!

int arr[5] = { 1,2,3,4,5 };
int* p = arr;

while (p!= arr + 5)
{
	std::cout << *p << std::endl;
	++p;	
}

