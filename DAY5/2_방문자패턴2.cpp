#include <iostream>
#include <list>
#include <vector>

// 모든 종류의 "방문자(Visitor) 클래스"가 지켜야 하는 인터페이스
template<typename T> struct IVisitor
{
	virtual void visit(T& e) = 0;
	virtual ~IVisitor() {}
};

// 모든 "방문의 대상(컨테이너)" 가 지켜야 하는 인터페이스
template<typename T> struct IContainer
{
	virtual void Accept(IVisitor<T>* visitor) = 0;
	virtual ~IContainer() {}
};
//==========================================
// 방문자들
// 핵심 : 방문자는 "요소 한개"에 대한 연산을 정의 하는 객체일뿐입니다.
template<typename T> class TwiceVisitor : public IVisitor<T>
{
public:
	virtual void visit(T& e) override { e *= 2; }
};

// STL 자체는 방문자 패턴으로 설계되지 않았읍니다.
// STL 확장해서 Accept 추가!
template<typename T>
class MyList : public std::list<T>, public IContainer<T>
{
public:
	using std::list<T>::list; // list 의 모든 생성자도 사용가능하게
							  // 생성자 상속

	virtual void Accept(IVisitor<T>* visitor) override
	{
		// 결국, 여기서 자신의 모든 요소를 방문자에 보내면 됩니다.
		for (auto& e : *this) // "*this" 자신, 즉 list 입니다.
			visitor->visit(e);
	}
};

int main()
{
	MyList<int> s = { 1,2,3,4,5,6,7,8,9,10 };

	TwiceVisitor<int> tv;	
	s.Accept(&tv);

//	ShowVisitor<int> sv;	
//	s.Accept(&sv);
}





