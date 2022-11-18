// DIP : Dependency Inversion Principle
//		=> �������� ������ ��Ģ
//		=> ��ü Ŭ������ �������� ���� �������̽��� �����ؼ� ����϶�!

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