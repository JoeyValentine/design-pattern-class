#include <mutex>

// ��� 1. ���ϴ� ���� �����Լ���! - template method!
// => List �� �ƴ϶� �پ��� �����̳�(�÷���)�� ���� �Ѵ�.
// => ���� �������� ����ȭ �ϴ� ������ �ڵ尡 ������� �ʰ�,,
//    ���� ���� �����ؾ� �Ѵ�.


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
	// �⺻ ������ �ƹ��ϵ� ���� �ʵ���
	virtual void lock()   {}
	virtual void unlock() {}
};
//=========================================================
// �����忡 ������ list �� �ʿ��ϸ� List �Ļ� Ŭ������ ����
// ����ȭ ����� �����ϸ� �ȴ�.
template<typename T> class ThreadSafeList : public List<T>
{
	std::mutex m;
public:
	virtual void lock()   { m.lock(); }
	virtual void unlock() { m.unlock(); }
};

List<int> st;			// ����ȭ ���� ���� list
ThreadSafeList<int> st2;// ����ȭ �Ǵ� list

int main()
{
	st.push_front(10);
}
