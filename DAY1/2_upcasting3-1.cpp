#include <iostream>

class Animal
{
public:
	int age;

	virtual ~Animal() {}  // ��� ��� Ŭ������ �Ҹ��ڰ� �����̾��
						// �մϴ�. ���� �ð��� ���ϴ�.
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
	// static_cast : ������ �ð��� �ϴ� ĳ����
	//				 p�� ����Ű�� ���� Dog �� �´��� ���� ���մϴ�.
	//               p�� ����Ű�� ���� Dog ��� Ȯ���� ��������
	//	             ����ؾ� �մϴ�.
	// Dog* pDog = static_cast<Dog*>(p);

	// dynamic_cast : ����ð� ĳ����
	//				  ����ð��� p�� ����Ű�� ���� Dog�� �´��� ������
	//				  ĳ����, ������� ����
	Dog* pDog = dynamic_cast<Dog*>(p);

	std::cout << pDog << std::endl;

	if (pDog != nullptr) // 0 ��� nullptr ����ϼ���(C++11)
	{
		pDog->color = 10; //!!
	}
}

int main()
{
	Dog    d; NewYear(&d);
	Cat    c; NewYear(&c);
}











