#include <iostream>

class Animal
{
public:
	int age;

	virtual ~Animal() {}  // 모든 기반 클래스는 소멸자가 가상이어야
						// 합니다. 다음 시간에 배웁니다.
};
class Cat : public Animal
{
};
class Dog : public Animal
{
public:
	int color;
};

void NewYear(Animal* p)
{
	++(p->age);

	// 세월이 지나서 새로운 요구사항이 생겼다.
	// p가 Dog 였다면 색상도 변경하고 싶다.
	// p->color = 10;	// error

	// Dog 고유 멤버에 접근하려면 캐스팅 해야 한다.
	// static_cast : 컴파일 시간에 하는 캐스팅
	//				 p가 가리키는 곳이 Dog 가 맞는지 조사 못합니다.
	//               p가 가리키는 곳이 Dog 라는 확신이 있을때만
	//	             사용해야 합니다.
	// Dog* pDog = static_cast<Dog*>(p);

	// dynamic_cast : 실행시간 캐스팅
	//				  실행시간에 p가 가리키는 곳이 Dog가 맞는지 조사후
	//				  캐스팅, 오버헤드 있음
	Dog* pDog = dynamic_cast<Dog*>(p);

	std::cout << pDog << std::endl;

	if (pDog != nullptr) // 0 대신 nullptr 사용하세요(C++11)
	{
		pDog->color = 10; //!!
	}
}

int main()
{
	Dog    d; NewYear(&d);
	Cat    c; NewYear(&c);
}











