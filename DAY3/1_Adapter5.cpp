#include <iostream>
#include <list>
#include <vector>
#include <deque>

// ��� 3. ��� ���� ������ ���� ��찡 �����ϴ�.
// => list �� �Ϻ� ����� ���������θ� ����Ѵٸ� ������ �����ϴ�.
// ��� : ��� ����� ���� �ް�, �ܺ� �����ϰڴ�.
// ���� : �Ϻ� ����� "���������θ� ���"�Ҷ�!

// ���԰� private ����� ��� "list�� ����� ���������θ� ���"
// �Ѵٴ� ������ �����մϴ�. �׷���,

// private ��� : list �� �����Լ��� override �Ҽ� �ִ�.
// ����         : list �� �����Լ��� override �Ҽ� ����!

// C++ list �� �����Լ� �����ϴ�. - ������ �����ϴ�

//
template<typename T> class stack 
{
	std::list<T> c; // �� Ÿ���Դϴ�. 
					// stack ������ ���ο� ����Ʈ�� ���� �˴ϴ�.
					// �ܺο� �̹� �����ϴ� list �� ����Ű�� ����
					// �ƴմϴ�.
					// �ᱹ Ŭ���� ����� �Դϴ�.

//	std::list<T>* c; // ������ �Ǵ� ����
					 // �ܺο� �̹� ������� list �� ����ų�� �ֽ��ϴ�.
					// �̷��� �Ǿ� �־�� ��ü ����� �Դϴ�.
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

	/*
	std::list<int> st;
	st.push_back(10);
	st.push_back(20);

	// �̹� ������� st ��ü�� ����ó�� ���̰� �ϰ� �ʹ�.
	stack<int> ss(&st); // �̷��� ��밡���ϸ� ��ü ����� �Դϴ�.
	*/
}