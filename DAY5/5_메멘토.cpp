// 8_�޸��� - 178
#include <iostream>


// ȭ�鿡 �׸��� �׸��� ����ϴ� Ŭ����
class Graphics
{
	// ���鰡���� �׸��� �Լ��� �����մϴ�.
}

int main()
{
	Graphics g;
	g.DrawLine(0, 0, 100, 100);

	// ���� �����̳� �β� ���� �����ϰ� �ͽ��ϴ�.

	// ��� 1. DrawLine()�� ���ڷ� ��������.
	// => windows api gdi+
	g.DrawLine(0, 0, 100, 100, red, 10);
	g.DrawLine(0, 0, 100, 100, red, 10);

	// ��� 2. Graphics ��ü�� �Ӽ������� ��������
	// => windows api gdi
	// => IOS �� cocoa ���̺귯�� 
	g.SetStrokeColor(red);
	g.SetStrokeWidth(10);
	g.SetStrokeStype(DASH);
	g.DrawLine(0, 0, 100, 100); // ������ ������ Stroke �Ӽ��� ���
	g.DrawLine(0, 0, 100, 100);
}









