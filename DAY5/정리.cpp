// 정리

// 핵심 1. 변하는 것을 분리하자!!

// 1. 변하는 것을 가상함수로 분리
//		template method
//		factory method

// 2. 변하는 것을 다른 클래스로 분리
//    => 인터페이스로 교체
//		 strategy : 알고리즘의 교체 - Edit/IValidator ( QT )
//		 state    : 상태에 따른 동작의 교체
//		 builder  : 복잡한 객체의 생성을 동일한 공정의 다른 표현으로 생성
// 
//	  => 템플릿 인자로 교체
//		 Policy Base Design

//=============================================
// 핵심 2. 재귀적 포함을 사용하는 디자인
// composite : 재귀적 포함을 사용한 복합객체 만들기 - PopupMenu/MenuItem
// decorator : 재귀적 포함을 사용한 동적인 기능의 추가 - FileStream/ZipDecorator

//=========================================
// 핵심 3. 다양한 문제 해결을 위한 간접층의 도입

// adapter : 인터페이스의 변경을 위한 간접층. 인터페이스의 불일치 해결
// 
// facade  : 사용하기 쉬운 포괄적 개념의 상위 인터페이스
// 
// bridge  : 추상과 구현의 분리를 통해 상호 독립적 update
// 
// proxy  : 범용적인 용도의 대행자.  - IPC 예제

//=========================================
// 핵심 4 : 열거, 통보
// iterator : 동일한 방법으로 열거
// visitor : 동일한 방법으로 연산
// observer : 1 : N의 관계로 통보
// 
// chain of responsibility : 요청을 고리에 따라 전달


// 핵심 5. : 객체를 생성하는 방법
// => static 멤버 함수로 생성
// => clone() 으로 복사 

// 핵심 6. 저장, 복구
// command : undo/redo 구현
// memento : 객체의 상태 저장.

//===============================================
// 생성패턴 5개 : singleton, prototype, abstract factory, 
//              factory method, builder 

// 구조패턴 7개 :
// 재귀적 포함 : decorator, composite
// 간접층     : adapter, proxy, bridge, facade
// 공유      : flyweight
//  
// 행위패턴 11개:	
//	변하는것 분리	: strategy, template method, state, 
//  통보, 열거, 반복 : iterator, visitor, observer, chain of responsibility
//  저장, 복구      : command, memento
//  기타				: mediatoer
//  컴파일러 같은 파서를 만들때 사용하는 패턴 : iterpreter 

