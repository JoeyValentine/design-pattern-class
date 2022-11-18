// SOLID : ��ü���� S/W �� ���鶧 ��Ű�� ���� ��Ģ��

// SRP : Single Responsibility Principle
//		=> �Ѱ��� Ŭ������ �Ѱ��� å�Ӹ� ������ �Ѵ�. 
// 
// OCP : Open-Close Principle 
//		=> Ȯ�忡�� ���� �ְ� ���濡���� ���� �־�� �Ѵ�.

// LSP : Liskov Substitution Principle
//		=> �Ļ� Ŭ������ ��� Ŭ������ ��ü �Ҽ� �־�� �Ѵ�.

// ISP : Interface Segregation Principle
//		=> �������̽� �и��� ��Ģ
//		=> �������̽��� ���� å��

// DIP : Dependency Inversion Principle
//		=> �������� ������ ��Ģ
//		=> ��ü Ŭ������ �������� ���� �������̽��� �����ؼ� ����϶�!

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