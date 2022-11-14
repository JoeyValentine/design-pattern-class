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

	// ������ ������ ���ο� �䱸������ �����.
	// p�� Dog ���ٸ� ���� �����ϰ� �ʹ�.
	// p->color = 10;	// error

	// Dog ���� ����� �����Ϸ��� ĳ���� �ؾ� �Ѵ�.
	Dog* pDog = static_cast<Dog*>(p);

	std::cout << pDog << std::endl;
}

int main()
{
	Dog    d; NewYear(&d);
	Cat    c; NewYear(&c);
}











