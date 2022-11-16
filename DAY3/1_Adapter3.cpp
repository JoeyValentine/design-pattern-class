#include <iostream>
#include <list>
#include <vector>
#include <deque>

// STL �� Adapter
// 1. C++ ǥ�ؿ��� �̹� linked list �� �ֽ��ϴ�.
// 2. �׷��� ����ڰ� stack �� �䱸 �մϴ�.(�̹� ������ ���ٰ� ����)

// stack �� ����� ��� 
// 1. stack �� ���Ӱ� ������!!
// 2. linked list �� ��� �Լ� �̸��� stack ó�� ��������.- adapter

// �Ʒ� Ŭ������ �ᱹ list �� ��� �Լ� �̸��� stack ó�� ���̵���
// �����Ѱ� �Դϴ�.
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