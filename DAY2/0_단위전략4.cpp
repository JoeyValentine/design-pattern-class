#include <iostream>

// ��� 3. ��������(policy base design)
// => Ŭ������ ����ϴ� ��å�� ���� ��å Ŭ������ ���ø� ���ڷ� ��ü�ϴ� ���
// => C++ �������� ���� ������ ���!!!!


// Ŭ������ ����ϴ� ��å(�˰���, ����)�� ��ü�ϴ� 2���� ���

// �������̽��� �����ؼ� ��ü : ����ð� ��ü ���� ( st.set_sync(&�ٸ���å) )
//						    �����Լ��� ����ϰ� �ȴ�. �Լ�ȣ���� �����������
//						    ���Ѿ��ϴ� ��Ģ�� "�������̽�(ISync)"�� ����
//							"strategy ����" - ��κ��� ��ü���� �������


// ���ø� ���ڷ� ��ü       : ����ð� ��ü �ȵ�.
//							��κ� �ζ��� �Լ� ���. �Լ� ȣ���� ������� ����
//							���Ѿ� �ϴ� ��Ģ�� "����ȭ" �ؾ� �Ѵ�.
//							"policy base design" - C++����� ��ǥ���� ���

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
//List<int, NoLock> st;
//List<int> st; // ok.. NoLock ���.
List<int, MutexLock> st;

int main()
{
	st.push_front(10);
}


// ����!!!

// STL �� �����̳ʰ� ��ó�� �Ǿ� ������ �ʽ��ϴ�
// => STL �����̳ʴ� ����ȭ�� ����ϰ� ���� �ʽ��ϴ�.
// => ����ȭ ����, �ٸ� ��å ��ü�� ���ؼ� "��������" ����մϴ� - ��������!!

// �����̳ʰ� ����ϴ� ����ȭ ��å�� ��ó�� �����ϴ� �ڵ��
// => ���¼ҽ��� "webkit" ���� ����մϴ�.