// ���ٺ�����

// ����� ǥ�� ��
// C++   : class Derived : public Base {}
// C#    : class Derived : Base {}
// SWIFT : class Derived : Base {}
// Python: class Derived(Base) {}
// Java  : class Derived extends Base {}


class Base
{
private:   int a;
protected: int b;
public:    int c;
};

// ���� ������ : ��� Ŭ������ ���� ����� ��ȣ�Ӽ��� "����Ҷ�" ���
class Derived : public Base
{
};

int main()
{
	Base    base;
	Derived derv;

	base.c = 10; // ok
	derv.c = 10; // ?
}