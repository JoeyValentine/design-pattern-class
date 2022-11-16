#include <iostream>
#include <list>
#include <vector>
#include <deque>

template<typename T, typename C = std::deque<T> > 
class stack
{
	C c; 
public:
	void push(const T& a) { c.push_back(a); }
	void pop()				{ c.pop_back(); }
	T& top()				{ return c.back(); }
};
int main()
{
	stack<int> s1; // std::deque
	stack<int, std::list<int>> s2;

	stack<int, std::vector<int>> s3; // std::vector 를
									 // stack 처럼 사용할수 있도록
									 // 변경해 달라는 것.

}