class Animal
{
public:
	int age;
};
class Dog : public Animal
{
public:
	int color;
};
int main()
{
	Dog d;

	Dog* p1 = &d;	// ok

//	int* p2 = &d;	// error
	
	// 핵심 1. 기반 클래스 포인터(참조)로 파생클래스를 가리킬수 있다.
	Animal* p3 = &d; // ok. upcasting
	Animal& r = d;   // ok
					 
	// 핵심 2. 기반 클래스 포인터로는 기반 클래스 멤버만 접근 가능하다.
	// => 컴파일러는 컴파일 시간의 p3의 타입을 보고 에러여부를 판단하므로
	// => 컴파일러는 p3가 무조건 Animal 을 가리킨다고 생각하기 때문에
	// => "static type check 언어" - C++, C#, java 등.!
	p3->age = 10;	// ok
	p3->color = 10; // error


	// 핵심 3. Animal* 타입인 p3로 Dog 고유 멤버에 접근하려면
	//       캐스팅 해야 합니다.
	// => 단, 이경우는 p3가 가리키는 곳이 Dog 이어야 합니다
	// => Dog 가 아닌경우, "잘못된 메모리 참조" 발생합니다.
	static_cast<Dog*>(p3)->color = 10;
	//         ((Dog*)p3)->color = 10; 

	// 핵심 4. 그럼, p3가 가리키는 곳이 Dog 가 맞는지 조사할수 있나요 ?
	// => dynamic_cast로하면 됩니다.
	// => 원리는 "가상함수 테이블"을 학습해 보세요
	// => 그런데, 조사하는 코드가 나오면 나쁜 디자인 입니다.
}











