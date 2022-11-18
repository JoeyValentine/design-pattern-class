#include <iostream>
#include <list>
#include <vector>

// ��� ������ "�湮��(Visitor) Ŭ����"�� ���Ѿ� �ϴ� �������̽�
template<typename T> struct IVisitor
{
	virtual void visit(T& e) = 0;
	virtual ~IVisitor() {}
};

// ��� "�湮�� ���(�����̳�)" �� ���Ѿ� �ϴ� �������̽�
template<typename T> struct IContainer
{
	virtual void Accept(IVisitor<T>* visitor) = 0;
	virtual ~IContainer() {}
};
//==========================================
// �湮�ڵ�
// �ٽ� : �湮�ڴ� "��� �Ѱ�"�� ���� ������ ���� �ϴ� ��ü�ϻ��Դϴ�.
template<typename T> class TwiceVisitor : public IVisitor<T>
{
public:
	virtual void visit(T& e) override { e *= 2; }
};

// STL ��ü�� �湮�� �������� ������� �ʾ����ϴ�.
// STL Ȯ���ؼ� Accept �߰�!
template<typename T>
class MyList : public std::list<T>, public IContainer<T>
{
public:
	using std::list<T>::list; // list �� ��� �����ڵ� ��밡���ϰ�
							  // ������ ���

	virtual void Accept(IVisitor<T>* visitor) override
	{
		// �ᱹ, ���⼭ �ڽ��� ��� ��Ҹ� �湮�ڿ� ������ �˴ϴ�.
		for (auto& e : *this) // "*this" �ڽ�, �� list �Դϴ�.
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





