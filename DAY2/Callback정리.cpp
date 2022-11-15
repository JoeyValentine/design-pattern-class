// Callback����
// 1. ��ü�� �Ѱ��� �̺�Ʈ�� �߻��Ҷ�
// => MenuItem �� "����" �� �ؾ��� �ϸ� �ִ�.

// => ��ü�� "�������̽�"�� �ƴ� "�Լ�(�ּ�)"�� ����ϴ°��� ���� ��찡 �����ϴ�.

// => cocoa(IOS) ���̺귯�������� "target - action" ����̶�� �θ��ϴ�.

// 2. ��ü�� ���������� �̺�Ʈ�� �߻��Ҷ�
// => ������ �Լ��� ���� ����ϸ��� �����ϱⰡ ������ ���ϴ�.
// => �̰�� "�������̽�"�� �����ϰ�, ��ü�� ����ϴ°��� ���մϴ�.
// => �� �̺�Ʈ�� �����ϴ� �Լ��̸��� ��ӵ˴ϴ�.
// => Listener ���
// => cocoa(IOS) ���̺귯������ "delegate"  �����̶�� �θ��ϴ�.

struct ISensorListener
{
	virtual void Fail() = 0;
	virtual void Update(int n) = 0;
};

class MyHandler : public ISensorListener {   };

MyHandler h;
sensor.add_listener(&h);

