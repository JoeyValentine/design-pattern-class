// ������.!!
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
// Bridge - �߻���
// Point.h
class PointImpl; // Ŭ���� ���漱��
				// �� �־
				// ������ ������ ��밡��
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


// �� �����
// "PIMPL" �̶�� �մϴ�

// 1. ������ �ð� �ӵ��� ��������
//   (�����ΰ� ���ص�, ����� �ڵ�� �ٽ� ����� �ʿ� ����.)

// 2. �������� �Ϻ��� ������ �����ϴ�.