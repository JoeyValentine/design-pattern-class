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

	// ������ ������ ���ο� �䱸������ �����.
	// p�� Dog ���ٸ� ���� �����ϰ� �ʹ�.
	p->color = 10;
}

int main()
{
	Dog    d; NewYear(&d);
	Cat    c; NewYear(&c);
}











