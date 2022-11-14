// 방법 2. 변하는 것을 다른 클래스로 - Strategy 패턴

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
List<int> st; 

int main()
{
	st.push_front(10);
}
