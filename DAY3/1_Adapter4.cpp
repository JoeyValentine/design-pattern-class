#include <iostream>
#include <list>
#include <vector>
#include <deque>

// 방법 2. private 상속
// => "구현은 물려 받지만 인터페이스를 물려 받지 않겠다" 라는 의도
// => stack  내부적으로는 list기능을 사용하지만, 
//    list 함수를 외부 노출하지 않겠다.

template<typename T> class stack : private std::list<T>
{
public:
	void push(const T& a) { std::list<T>::push_back(a); }
	void push()			  { std::list<T>::pop_back(); }
	T& pop()			  { return std::list<T>::back(); }
};

int main()
{
	stack<int> s;
	s.push(10);

	s.push_front(30);	// error. 
						// private 상속 이므로 list 의 모든 멤버함수
						// 는 외부에서 호출할수 없다.
}