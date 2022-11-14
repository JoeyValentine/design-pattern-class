// 1_추상클래스1.cpp - 10page

// 추상 클래스 : 순수 가상함수가 한개 이상 있는 클래스
// 특징 : 객체를 만들수 없다.
// 의도 : 파생 클래스 만들때 반드시 "특정함수를 만들라고 지시" 하는 것
class Shape
{
public:
	virtual void Draw() = 0; // 순수 가상함수(pure virtual function)
							// 구현부가 없고, "=0"으로 끝나는 함수						 
};
class Rect : public Shape
{
	// Draw()의 구현부를 제공하지 않으면 역시 추상 클래스이다.
	// Draw()의 구현을 제공하면 "추상이 아닌 구체(concrete) 클래스"
public:
	virtual void Draw() {} // 구현부 제공
};
int main()
{
//	Shape  s; // error. 추상 클래스는 객체 생성 안됨
	Shape* p; // ok.    포인터 변수는 만들수 있다.
	Rect  r;  // ok!
}

// java, C# : abstract 키워드가 있습니다.
/*
abstract class Shape
{
public:
	abstract void Draw();
};
*/