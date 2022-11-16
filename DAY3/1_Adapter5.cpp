#include <iostream>
#include <list>
#include <vector>
#include <deque>

// 방법 3. 상속 보다 포함이 좋은 경우가 많습니다.
// => list 의 일부 기능을 내부적으로만 사용한다면 포함이 좋습니다.
// 상속 : 모든 기능을 물려 받고, 외부 노출하겠다.
// 포함 : 일부 기능을 "내부적으로만 사용"할때!

template<typename T> class stack 
{
	std::list<T> c;
public:
	void push(const T& a) { c.push_back(a); }
	void pop()			  { c.pop_back(); }
	T& top()			  { return c.back(); }
};

int main()
{
	stack<int> s;
	s.push(10);

//	s.push_front(30);	
}