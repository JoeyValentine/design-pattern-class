// SOLID : 객체지향 S/W 를 만들때 지키면 좋은 원칙들

// SRP : Single Responsibility Principle
//		=> 한개의 클래스는 한개의 책임만 가져야 한다. 
// 
// OCP : Open-Close Principle 
//		=> 확장에는 열려 있고 변경에서는 닫혀 있어야 한다.

// LSP : Liskov Substitution Principle
//		=> 파생 클래스는 기반 클래스를 대체 할수 있어야 한다.

// ISP : Interface Segregation Principle
//		=> 인터페이스 분리의 원칙
//		=> 인터페이스의 단일 책임

// DIP : Dependency Inversion Principle
//		=> 의존관계 역전의 원칙
//		=> 구체 클래스에 의존하지 말고 인터페이스에 의존해서 통신하라!

// ISP
struct IMP3		// bad
{
	virtual void play() = 0;
	virtual void stop() = 0;
	virtual void uploadSNS = 0;
};

struct IMP3		// good
{
	virtual void play() = 0;
	virtual void stop() = 0;
};

struct ISNS
{
	virtual void uploadSNS = 0;
};

class GoodMP3 : public IMP3, public ISNS
{
};