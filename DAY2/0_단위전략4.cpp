#include <iostream>
// 방법 3. 단위전략(policy base design)
// => 클래스가 사용하는 정책을 담은 정책 클래스를 템플릿 인자로 교체하는 기술
// => C++ 진영에서 가장 유명한 기법!!!!

template<typename T, typename ThreadModel > class List
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
List<int, NoLock> st;

int main()
{
	st.push_front(10);
}
