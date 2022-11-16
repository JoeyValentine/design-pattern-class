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
// 방법 1. public 상속을 사용한 stack
// => list 의 모든 기능도 사용자가 사용할수 있게 된다. 
// => 좋지않은 설계
// => java 의 stack 은 Vector 에서 상속됩니다.!!
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

	s.push_front(30); // stack 자체의 멤버 함수는 아니지만
					  // list로 부터 물려 받은 멤버 함수
					  // stack 은 한쪽으로만 사용해야 하는데!!!
						// => 앞으로 접근했으므로 스택이 잘못되었다.
}