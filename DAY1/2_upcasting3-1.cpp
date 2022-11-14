// upcasting3.cpp
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
	p->color = 10;
}

int main()
{
	Dog    d; NewYear(&d);
	Cat    c; NewYear(&c);
}











