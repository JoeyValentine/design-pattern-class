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
// 기존 코드의 수정 보다는
// 새로운 코드의 추가가 좀더 안전합니다.

void NewYear(Dog* p)
{
	// 기존의 기능을 먼저 실행하고
	NewYear( static_cast<Animal*>(p) );

	// 새로운 요구 조건을 실행
	p->color = 10;
}

int main()
{
	Dog    d; NewYear(&d);
	Cat    c; NewYear(&c);
}











