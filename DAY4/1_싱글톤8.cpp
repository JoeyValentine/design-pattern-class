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
	static Cursor& getInstance()
	{
		std::lock_guard<std::mutex> g(mtx);

		if (pinstance == nullptr)
			pinstance = new Cursor;
		
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

