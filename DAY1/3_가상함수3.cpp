// 2_�����Լ�������
class Base
{
public:
	virtual void foo() {}
	virtual void goo(int) {}
};
class Derived : public Base
{
public:
	// �ٽ� 1. �����Լ� �����ǽ� virtual �� �ٿ����ǰ� 
	//        �Ⱥٿ��� �˴ϴ�. 
	//        �Ⱥٿ��� "virtual" �Դϴ�.
	//        => �������� ���ؼ���� �ǵ��� ���̼���..
	// virtual void foo() {}

	// �ٽ� 2. �����Լ� �����ǽ� "��Ÿ�� �Լ��̸��� Ʋ����" ������ �ƴմϴ�.
	// => ���ο� �����Լ��� ������ٰ� �����Ϸ��� �����մϴ�.
	// => �̷� Ư¡�� ������ �����̾����ϴ�.
	virtual void fooo() {}
	virtual void goo(double){}

	// �ٽ� 3. �����Լ� �����ǽ� override Ű���带 ���̼���(C++11)
	// => ���ο� �����Լ��� ����� ���� �ƴ϶�
	//    ��� Ŭ���� �����Լ��� override �Ѵٰ� �˸��� ��
	virtual void fooo() override {}
};

int main()
{
}





