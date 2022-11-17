#include <iostream>
#include <mutex>

// 힙에 만드는 모델과 멀티스레드 안정성

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
		mtx.lock();

		if (pinstance == nullptr)
			pinstance = new Cursor;
	
		mtx.unlock();
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

