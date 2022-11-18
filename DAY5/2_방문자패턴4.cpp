// 방문자 패턴의 의미!!
class Shape
{
	virtual void Draw() = 0;
};
class Rect   : public Shape {};
class Circle : public Shape {};

// 전통적인 객체지향 디자인
// => ? 자리에 (1). 쉽다  (2). 어렵다 로 채워 보세요.

// 클래스의 추가    : 쉽다. 다형성 기반으로 "OCP" 를 만족하게 설계 했다면
//					기존 코드를 수정하지 않고도 새로운 도형을 추가할수 있다.
// 
// 가상 함수의 추가 : 어렵다. Shape 에 move() 를 추가하면
//						  모든 파생 클래스가 변경(move 구현)되어야 한다





// 그런데, Move()라는 가상함수를 추가하지말고!!
ShapeMoveVisitor v;
컨테이너.accept(&v); // 이렇게 하면 ??




// 방문자 패턴으로 디자인 하면
// 클래스의 추가   : 어렵다. "IMenuVisitor" 를 생각해 보세요
//					"DIP" 위반 아닌가요 ?
//					"DIP를 위반 해서 클래스 추가가 어려워진것"
					struct IMenuVisitor
					{
						virtual void visit(MenuItem* mi) = 0;
						virtual void visit(PopupMenu* pm) =0; 
						virtual ~IMenuVisitor() {}
					};


// 가상 함수의 추가 : 쉽다. 
//				=> 실제로 가상함수를 추가하는 것이 아니라
//				=> 가상함수가 하는 일을 방문자 객체로 만들면 된다는 의미

					
// 방문자
// "타입의 확장" 이 아닌 "가상함수의 확장" 에 개념

