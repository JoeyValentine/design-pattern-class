// 접근변경자

// 상속을 표기 법
// C++   : class Derived : public Base {}
// C#    : class Derived : Base {}
// SWIFT : class Derived : Base {}
// Python: class Derived(Base) {}
// Java  : class Derived extends Base {}


class Base
{
private:   int a;
protected: int b;
public:    int c;
};

// 접근 변경자 : 기반 클래스가 가진 멤버의 보호속성을 "축소할때" 사용
class Derived : public Base
{
};

int main()
{
	Base    base;
	Derived derv;

	base.c = 10; // ok
	derv.c = 10; // ?
}