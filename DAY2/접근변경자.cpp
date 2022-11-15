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
// 								"확장(protected->public등)은 안됩니다."
//class Derived : public Base
//class Derived : protected Base  // 기반 클래스의 public 멤버를
								// protected로 변경해서 상속받겠다는것 
class Derived : private Base  // Base의 public, protected 멤버를
{							  // private 으로 변경해서 상속
};

int main()
{
	Base    base;
	Derived derv;

	base.c = 10; // ok
//	derv.c = 10; // error. private 상속이므로 
				 // Derived 의 c 는 private 멤버 입니다.

	// 주의 public 상속만 upcasting 됩니다.
	Base* p = &derv; // public 상속 : ok
					 // protected, private 상속 : error
}