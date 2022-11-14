// 2_upcasting3-2 - 3번 복사하세요.
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
}

int main()
{
	Dog    d; NewYear(&d);
	Cat    c; NewYear(&c);
}











