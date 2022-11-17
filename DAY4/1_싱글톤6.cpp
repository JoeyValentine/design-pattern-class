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
	// 최초 호출 : if 문이 한번이면 되는 것을 2회를 사용한다.
	//           "if 문 추가 사용" 때문에 오버헤드있음
	// 나머지 호출 : lock/unlock 을 사용하지 않기 때문에 빨라진다.
	
	// "DCLP(Double Check Locking Pattern)" 이라고 불리는 기술
	// C#, Java 등의 언어에서는 꽤 유명한 모델!
	// C++ 에서는 절대 사용하지 마세요 - 버그 입니다.
	// ( 2004년 이전까지 널리 사용되었는데, 2004년 논문으로 버그라고 발표)               
	static Cursor& getInstance()
	{
		if (pinstance == nullptr)
		{
			mtx.lock();
		
			if (pinstance == nullptr)
			{
				pinstance = new Cursor;
			}
			
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

