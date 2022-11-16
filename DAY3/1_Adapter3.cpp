#include <iostream>
#include <list>
#include <vector>
#include <deque>

// STL 과 Adapter
// 1. C++ 표준에는 이미 linked list 가 있습니다.
// 2. 그런데 사용자가 stack 을 요구 합니다.(이미 있지만 없다고 가정)

// stack 을 만드는 방법 
// 1. stack 을 새롭게 만들자!!
// 2. linked list 의 멤버 함수 이름을 stack 처럼 변경하자.- adapter

// 아래 클래스는 결국 list 의 멤버 함수 이름을 stack 처럼 보이도록
// 변경한것 입니다.
template<typename T> class stack : public std::list<T>
{
public:
	void push(const T& a) {	std::list<T>::push_back(a);	}
	void push()           { std::list<T>::pop_back(); }
	T&   pop()            { return std::list<T>::back();}
};

int main()
{
	stack<int> s;
	s.push(10);
}