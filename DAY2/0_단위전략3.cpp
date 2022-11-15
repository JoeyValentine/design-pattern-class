// 방법 2. 변하는 것을 다른 클래스로 - Strategy 패턴
// => 동기화 정책을 담은 클래스를 다양한 컨테이너에서 모두 활용할수 있다.
// => 동기화 정책을 수행하는 함수가 가상함수이다. - 느리다.!!


// 동기화 정책을 담은 클래스는 반드시 아래 인터페이스를 구현해야 한다.
struct ISync
{
	virtual void lock() = 0;
	virtual void unlock() = 0;
	virtual ~ISync() {}
};
template<typename T> class List
{
	ISync* psync = nullptr; // 동기화 정책을 담은 객체 연결.!
public:
	void set_sync(ISync* p) { psync = p; }

	void push_front(const T& a)
	{
		if (psync) psync->lock();
		//......
		if (psync) psync->unlock();
	}
};
//===========================
// 동기화 정책을 담은 정책 클래스 설계
class linux_mutex_lock : public ISync
{
	// pthread_mutex_t mtx;
public:
	virtual void lock()   { } // pthread_acquire_mutex()
	virtual void unlock() { } // release
};

List<int> st; 

int main()
{
	linux_mutex_lock ml;
	st.set_sync(&ml); // 컨테이너에 동기화 정책 연결

	st.push_front(10);
}
