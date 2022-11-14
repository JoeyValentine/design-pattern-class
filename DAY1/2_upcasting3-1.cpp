#include <iostream>

class Animal
{
public:
	int age;
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
	Dog* pDog = static_cast<Dog*>(p);

	std::cout << pDog << std::endl;
}

int main()
{
	Dog    d; NewYear(&d);
	Cat    c; NewYear(&c);
}











