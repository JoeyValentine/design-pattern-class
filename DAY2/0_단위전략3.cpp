// ��� 2. ���ϴ� ���� �ٸ� Ŭ������ - Strategy ����

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
List<int> st; 

int main()
{
	st.push_front(10);
}
