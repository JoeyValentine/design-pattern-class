// 2_upcasting3-2 - 3�� �����ϼ���.
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
// ���� �ڵ��� ���� ���ٴ�
// ���ο� �ڵ��� �߰��� ���� �����մϴ�.

void NewYear(Dog* p)
{
	// ������ ����� ���� �����ϰ�
	NewYear( static_cast<Animal*>(p) );

	// ���ο� �䱸 ������ ����
	p->color = 10;
}

int main()
{
	Dog    d; NewYear(&d);
	Cat    c; NewYear(&c);
}











