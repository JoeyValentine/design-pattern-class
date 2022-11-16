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
#include <stack> // C++ ǥ���� stack �� ��ó�� �Ǿ� �ֽ��ϴ�.
				 // ���� "stack adapter" ��� �� ����մϴ�.
				 // Policy Base Design ���� "�����̳� ��ü �����մϴ�."
					// �����̳ʿ��� �ݵ�� push_back, pop_back, back()
					// �� �־�� �մϴ�.
int main()
{
	std::stack<int> s1; // std::deque
	std::stack<int, std::list<int>> s2;

	std::stack<int, std::vector<int>> s3; // std::vector ��
									 // stack ó�� ����Ҽ� �ֵ���
									 // ������ �޶�� ��.
	s1.push(10);

}