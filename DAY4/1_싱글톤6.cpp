#include <iostream>
#include <mutex>


class Cursor
{
private:
	Cursor() { std::cout << "Cursor()" << std::endl; }

	Cursor(const Cursor&) = delete;
	Cursor operator=(const Cursor&) = delete;

	static Cursor* pinstance;
	static std::mutex mtx;
public:
	// 아래 함수를 "100번" 호출했을때를 생각해 보세요
	// => 최초 객체 생성시는 동기화가 필요 하지만
	// => 나머지 99번은 동기화 필요 없습니다.
	/*
	static Cursor& getInstance()
	{
		mtx.lock();
		if (pinstance == nullptr)
			pinstance = new Cursor;
		mtx.unlock();

		return *pinstance;
	}
	*/
	// 최초 호출 : 
	static Cursor& getInstance()
	{
		if (pinstance == nullptr)
		{
			mtx.lock();
		
			if (pinstance == nullptr)
				pinstance = new Cursor;
			
			mtx.unlock();
		}
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

