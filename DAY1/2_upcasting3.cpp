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

// upcasting Ȱ�� 2. ������ ó���ϴ� �Լ��� ����� �ִ�.
//void NewYear(Dog* p)	// Dog �� ���� �޴� �Լ�!
void NewYear(Animal* p) // ��� ������ ���� �޴� �Լ�
{
	++(p->age); 	
}

int main()
{
	Dog    d; NewYear(&d);
	Cat    c; NewYear(&c);
}











