#include <iostream>
#include <list>
#include <vector>
#include <deque>

// 방법 3. 상속 보다 포함이 좋은 경우가 많습니다.
// => list 의 일부 기능을 내부적으로만 사용한다면 포함이 좋습니다.
// 상속 : 모든 기능을 물려 받고, 외부 노출하겠다.
// 포함 : 일부 기능을 "내부적으로만 사용"할때!

// 포함과 private 상속은 모두 "list의 기능을 내부적으로만 사용"
// 한다는 점에서 유사합니다. 그런데,

// private 상속 : list 의 가상함수를 override 할수 있다.
// 포함         : list 의 가상함수를 override 할수 없다!

// C++ list 는 가상함수 없습니다. - 포함이 좋습니다

//
template<typename T> class stack 
{
	std::list<T> c; // 값 타입입니다. 
					// stack 생성시 새로운 리스트가 생성 됩니다.
					// 외부에 이미 존재하는 list 를 가리키는 것이
					// 아닙니다.
					// 결국 클래스 어답터 입니다.

//	std::list<T>* c; // 포인터 또는 참조
					 // 외부에 이미 만들어진 list 를 가리킬수 있습니다.
					// 이렇게 되어 있어야 객체 어답터 입니다.
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

	// 이미 만들어진 st 객체를 스택처럼 보이게 하고 싶다.
	stack<int> ss(&st); // 이렇게 사용가능하면 객체 어답터 입니다.
	*/
}