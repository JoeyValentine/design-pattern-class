// DIP : Dependency Inversion Principle
//		=> 의존관계 역전의 원칙
//		=> 구체 클래스에 의존하지 말고 인터페이스에 의존해서 통신하라!

class People
{
public:
	void useCamera(Camera* p) {}	// bad
	void useCamera(ICamera* p) {}	// good
};

class MenuItem
{
	IMenuListener* listener;
public:
	void set_listener(IMenuListener* p) { listener = p; }
		
	void Command()
	{
		listener->do_command();
	}
};