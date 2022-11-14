// 1_�߻�Ŭ����1.cpp - 10page

// �߻� Ŭ���� : ���� �����Լ��� �Ѱ� �̻� �ִ� Ŭ����
// Ư¡ : ��ü�� ����� ����.
// �ǵ� : �Ļ� Ŭ���� ���鶧 �ݵ�� "Ư���Լ��� ������ ����" �ϴ� ��
class Shape
{
public:
	virtual void Draw() = 0; // ���� �����Լ�(pure virtual function)
							// �����ΰ� ����, "=0"���� ������ �Լ�						 
};
class Rect : public Shape
{
	// Draw()�� �����θ� �������� ������ ���� �߻� Ŭ�����̴�.
	// Draw()�� ������ �����ϸ� "�߻��� �ƴ� ��ü(concrete) Ŭ����"
public:
	virtual void Draw() {} // ������ ����
};
int main()
{
//	Shape  s; // error. �߻� Ŭ������ ��ü ���� �ȵ�
	Shape* p; // ok.    ������ ������ ����� �ִ�.
	Rect  r;  // ok!
}

// java, C# : abstract Ű���尡 �ֽ��ϴ�.
/*
abstract class Shape
{
public:
	abstract void Draw();
};
*/