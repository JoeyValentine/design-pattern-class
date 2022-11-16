#include <iostream>
#include <list>
#include <vector>
#include <deque>

// ��� 2. private ���
// => "������ ���� ������ �������̽��� ���� ���� �ʰڴ�" ��� �ǵ�
// => stack  ���������δ� list����� ���������, 
//    list �Լ��� �ܺ� �������� �ʰڴ�.

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
						// private ��� �̹Ƿ� list �� ��� ����Լ�
						// �� �ܺο��� ȣ���Ҽ� ����.
}