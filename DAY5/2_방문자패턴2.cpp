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







int main()
{
	std::list<int> s = { 1,2,3,4,5,6,7,8,9,10 };

	TwiceVisitor<int> tv;	
	s.Accept(&tv);

	ShowVisitor<int> sv;	
	s.Accept(&sv);
}





