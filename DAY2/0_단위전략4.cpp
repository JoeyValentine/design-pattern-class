#include <iostream>

// 방법 3. 단위전략(policy base design)
// => 클래스가 사용하는 정책을 담은 정책 클래스를 템플릿 인자로 교체하는 기술
// => C++ 진영에서 가장 유명한 기법!!!!


// 클래스가 사용하는 정책(알고리즘, 전략)을 교체하는 2가지 기술

// 인터페이스를 설계해서 교체 : 실행시간 교체 가능 ( st.set_sync(&다른정책) )
//						    가상함수를 사용하게 된다. 함수호출의 오버헤드존재
//						    지켜야하는 규칙을 "인터페이스(ISync)"로 설계
//							"strategy 패턴" - 대부분의 객체지향 언어지원


// 템플릿 인자로 교체       : 실행시간 교체 안됨.
//							대부분 인라인 함수 사용. 함수 호출의 오버헤드 없음
//							지켜야 하는 규칙은 "문서화" 해야 한다.
//							"policy base design" - C++언어의 대표적인 기술

template<typename T, typename ThreadModel = NoLock > class List
{
	ThreadModel tm;
public:
	void push_front(const T& a)
	{
		tm.lock();
		//......
		tm.unlock();
	}
};
//===============================================
// 동기화 정책을 담은 클래스를 설계 합니다
// => 단위전략에서 모든 정책 클래스는 지켜야 하는 규칙이 있는데.
//    위 코드 같은 경우는 반드시 lock()/unlock() 이 있어야 합니다.
class NoLock
{
public:
	inline void lock() {}
	inline void unlock() {}
};
class MutexLock
{
public:
	inline void lock()   { std::cout << "mutex lock" << std::endl; }
	inline void unlock() { std::cout << "mutex unlock" << std::endl; }
};
//==========================================
//List<int, NoLock> st;
//List<int> st; // ok.. NoLock 사용.
List<int, MutexLock> st;

int main()
{
	st.push_front(10);
}


// 참고!!!

// STL 의 컨테이너가 위처럼 되어 있지는 않습니다
// => STL 컨테이너는 동기화를 고려하고 있지 않습니다.
// => 동기화 말고, 다른 정책 교체를 위해서 "단위전략" 사용합니다 - 다음예제!!

// 컨테이너가 사용하는 동기화 정책을 위처럼 변경하는 코드는
// => 오픈소스인 "webkit" 에서 사용합니다.