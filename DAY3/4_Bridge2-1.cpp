// 구현층.!!
// PointImpl.h
class PointImpl
{
	int x, y;
public:
	void printImpl();
};

// PointImpl.cpp
#include "PointImpl.h"

void PointImpl::print() { }
//======================================
// Bridge - 추상층
// Point.h
class PointImpl; // 클래스 전방선언
				// 만 있어도
				// 포인터 변수는 사용가능
class Point
{
	PointImpl* pImpl;
public:
	Point();
	void print();
};

// Point.cpp
#include "PointImpl.h"
#include "Point.h"

Point::Point() { pImpl = new PointImpl; }
void Point::print() { pImpl->pImpl(); }
//---------------------------------------





// main.cpp
#include "Point.h"
int main()
{
	Point p;
	p.print();
}


// 위 기술을
// "PIMPL" 이라고 합니다

// 1. 컴파일 시간 속도가 빠라지고
//   (구현부가 변해도, 사용자 코드는 다시 빌드될 필요 없다.)

// 2. 구현부의 완벽한 은닉이 가능하다.