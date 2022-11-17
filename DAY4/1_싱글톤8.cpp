#include <iostream>
#include <mutex>

// CRTP ( Curiously Recurring Template Pattern )
// => ��� Ŭ���� ���鶧 �Ļ� Ŭ���� �̸��� Ȱ���Ҽ� �ְ� �ϴ� ���
// => �Ļ� Ŭ������ �ڽ��� �̸��� ��� Ŭ������ ���ø� ���ڷ� �����ϴ� ���
// => ���� ���¼ҽ��� ���� ���� ����ϴ� "C++ IDioms" ���

template<typename T> 
class Singleton
{
protected:
	Singleton() { }

	Singleton(const Singleton&) = delete;
	Singleton operator=(const Singleton&) = delete;

	static T* pinstance; // <<==== 1
	static std::mutex mtx;
public:
	static T& getInstance()		// <<====== 2
	{
		std::lock_guard<std::mutex> g(mtx);

		if (pinstance == nullptr)
			pinstance = new T;   // <==== 3
		
		return *pinstance;
	}
};
template<typename T> T* Singleton<T>::pinstance = nullptr;   // <<=== 4
template<typename T> std::mutex Singleton<T>::mtx;


// Mouse Ŭ������ "Cursor ó�� ���� ����� �̱��� ��" �� �ϰ�ͽ��ϴ�
class Mouse : public Singleton< Mouse  > 
{

};


int main()
{
	Mouse& m1 = Mouse::getInstance();
	Mouse& m2 = Mouse::getInstance();
}

// github.com/aosp-mirror     => �ȵ���̵� �ҽ� �ڵ� �Դϴ�.
//								Android Open Source Project
// 
// platform system core ��� �������丮 �����ϼ���

// libutils/include/utils/singleton.h ���� Ȯ���� ������