#include <iostream>
#include "helper.h"

/*
// "Meyer's 싱글톤 코드" 를 자동생성하는 매크로 제공
#define MAKE_SINGLETON(classname)						\
private:												\
	classname() {  }									\
	classname(const classname&) = delete;				\
	classname operator=(const classname&) = delete;		\
public:													\
	static classname& getInstance()						\					
	{													\
		static classname instance;						\
		return instance;								\
	}
*/

class Cursor
{
	MAKE_SINGLETON(Cursor)
};

int main()
{
	Cursor& c1 = Cursor::getInstance();
	Cursor& c2 = Cursor::getInstance();

}

