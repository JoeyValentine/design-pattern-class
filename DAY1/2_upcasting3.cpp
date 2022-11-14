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

// upcasting 활용 2. 동종을 처리하는 함수를 만들수 있다.
//void NewYear(Dog* p)	// Dog 만 전달 받는 함수!
void NewYear(Animal* p) // 모든 동물을 전달 받는 함수
{
	++(p->age); 	
}

int main()
{
	Dog    d; NewYear(&d);
	Cat    c; NewYear(&c);
}











