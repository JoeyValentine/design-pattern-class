// ��� 2. ���ϴ� ���� �ٸ� Ŭ������ - Strategy ����
// => ����ȭ ��å�� ���� Ŭ������ �پ��� �����̳ʿ��� ��� Ȱ���Ҽ� �ִ�.
// => ����ȭ ��å�� �����ϴ� �Լ��� �����Լ��̴�. - ������.!!


// ����ȭ ��å�� ���� Ŭ������ �ݵ�� �Ʒ� �������̽��� �����ؾ� �Ѵ�.
struct ISync
{
	virtual void lock() = 0;
	virtual void unlock() = 0;
	virtual ~ISync() {}
};
template<typename T> class List
{
	ISync* psync = nullptr; // ����ȭ ��å�� ���� ��ü ����.!
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
// ����ȭ ��å�� ���� ��å Ŭ���� ����
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
	st.set_sync(&ml); // �����̳ʿ� ����ȭ ��å ����

	st.push_front(10);
}
