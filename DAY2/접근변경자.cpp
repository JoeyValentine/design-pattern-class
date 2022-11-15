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
// 								"Ȯ��(protected->public��)�� �ȵ˴ϴ�."
//class Derived : public Base
//class Derived : protected Base  // ��� Ŭ������ public �����
								// protected�� �����ؼ� ��ӹްڴٴ°� 
class Derived : private Base  // Base�� public, protected �����
{							  // private ���� �����ؼ� ���
};

int main()
{
	Base    base;
	Derived derv;

	base.c = 10; // ok
//	derv.c = 10; // error. private ����̹Ƿ� 
				 // Derived �� c �� private ��� �Դϴ�.

	// ���� public ��Ӹ� upcasting �˴ϴ�.
	Base* p = &derv; // public ��� : ok
					 // protected, private ��� : error
}