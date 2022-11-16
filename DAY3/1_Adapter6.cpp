#include <iostream>
#include <list>
#include <vector>
#include <deque>
/*
template<typename T, typename C = std::deque<T> > 
class stack
{
	C c; 
public:
	inline void push(const T& a) { c.push_back(a); }
	inline void pop()				{ c.pop_back(); }
	inline T& top()				{ return c.back(); }
};
*/
#include <stack> // C++ 표준의 stack 이 위처럼 되어 있습니다.
				 // 흔히 "stack adapter" 라는 용어를 사용합니다.
				 // Policy Base Design 으로 "컨테이너 교체 가능합니다."
					// 컨테이너에는 반드시 push_back, pop_back, back()
					// 이 있어야 합니다.
int main()
{
	std::stack<int> s1; // std::deque
	std::stack<int, std::list<int>> s2;

	std::stack<int, std::vector<int>> s3; // std::vector 를
									 // stack 처럼 사용할수 있도록
									 // 변경해 달라는 것.
	s1.push(10);

}