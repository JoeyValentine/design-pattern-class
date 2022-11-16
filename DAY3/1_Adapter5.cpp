#include <iostream>
#include <list>
#include <vector>
#include <deque>

// ��� 3. ��� ���� ������ ���� ��찡 �����ϴ�.
// => list �� �Ϻ� ����� ���������θ� ����Ѵٸ� ������ �����ϴ�.
// ��� : ��� ����� ���� �ް�, �ܺ� �����ϰڴ�.
// ���� : �Ϻ� ����� "���������θ� ���"�Ҷ�!

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