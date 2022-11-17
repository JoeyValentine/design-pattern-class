// 1_�̱���7 - 5�� ����
#include <iostream>
#include <mutex>

// �ڿ��� ȹ��/�ݳ��� �ǵ��� �������� ������
// ������/�Ҹ��ڿ� �����ؼ� ����ϼ���
template<typename T> class lock_guard
{
	T& mtx;
public:
	lock_guard(T& m) : mtx(m) { m.lock(); }
	~lock_guard()             { m.unlock(); }
};



class Cursor
{
private:
	Cursor() { std::cout << "Cursor()" << std::endl; }

	Cursor(const Cursor&) = delete;
	Cursor operator=(const Cursor&) = delete;

	static Cursor* pinstance;
	static std::mutex mtx;
public:


	static Cursor& getInstance()
	{
		lock_guard<std::mutex> g(mtx);

//		mtx.lock();

		if (pinstance == nullptr)
			pinstance = new Cursor;

//		mtx.unlock();

		return *pinstance;
	}



};
Cursor* Cursor::pinstance = nullptr;
std::mutex Cursor::mtx;


int main()
{
	Cursor& c1 = Cursor::getInstance();
	Cursor& c2 = Cursor::getInstance();

}

