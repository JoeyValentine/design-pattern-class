#include <mutex>

// 방법 1. 변하는 것을 가상함수로! - template method!
// => List 뿐 아니라 다양한 컨테이너(컬렉션)이 존재 한다.
// => 현재 디자인은 동기화 하는 유사한 코드가 재사용되지 않고,,
//    각각 따로 구현해야 한다.


template<typename T> class List
{	
public:
	void push_front(const T& a)
	{
		lock();
		// 
		// ......
		// 
		unlock();
	}	
	// 기본 구현은 아무일도 하지 않도록
	virtual void lock()   {}
	virtual void unlock() {}
};
//=========================================================
// 스레드에 안전한 list 가 필요하면 List 파생 클래스를 만들어서
// 동기화 방법만 제공하면 된다.
template<typename T> class ThreadSafeList : public List<T>
{
	std::mutex m;
public:
	virtual void lock()   { m.lock(); }
	virtual void unlock() { m.unlock(); }
};

List<int> st;			// 동기화 되지 않은 list
ThreadSafeList<int> st2;// 동기화 되는 list

int main()
{
	st.push_front(10);
}
