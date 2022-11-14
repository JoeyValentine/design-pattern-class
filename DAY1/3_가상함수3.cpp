// 2_가상함수재정의
class Base
{
public:
	virtual void foo() {}
	virtual void goo(int) {}
};
class Derived : public Base
{
public:
	// 핵심 1. 가상함수 재정의시 virtual 은 붙여도되고 
	//        안붙여도 됩니다. 
	//        안붙여도 "virtual" 입니다.
	//        => 가독성을 위해서라면 되도록 붙이세요..
	// virtual void foo() {}

	// 핵심 2. 가상함수 재정의시 "오타로 함수이름이 틀려도" 에러는 아닙니다.
	// => 새로운 가상함수를 만들었다고 컴파일러가 생각합니다.
	// => 이런 특징이 버그의 원인이었습니다.
	virtual void fooo() {}
	virtual void goo(double){}

	// 핵심 3. 가상함수 재정의시 override 키워드를 붙이세요(C++11)
	// => 새로운 가상함수를 만드는 것이 아니라
	//    기반 클래스 가상함수를 override 한다고 알리는 것
	virtual void fooo() override {}
};

int main()
{
}





