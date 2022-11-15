#include <iostream>
// ��� 3. ��������(policy base design)
// => Ŭ������ ����ϴ� ��å�� ���� ��å Ŭ������ ���ø� ���ڷ� ��ü�ϴ� ���
// => C++ �������� ���� ������ ���!!!!

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
// ����ȭ ��å�� ���� Ŭ������ ���� �մϴ�
// => ������������ ��� ��å Ŭ������ ���Ѿ� �ϴ� ��Ģ�� �ִµ�.
//    �� �ڵ� ���� ���� �ݵ�� lock()/unlock() �� �־�� �մϴ�.
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
