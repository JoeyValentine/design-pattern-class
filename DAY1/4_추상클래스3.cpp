#include <iostream>


// ī�޶�� ī�޶� ����ڸ� ���� �������� ����
// "���Ѿ� �ϴ� ��Ģ(�������̽�)"�� ���� ���� ����.

// ��Ģ : ��� ī�޶�� �Ʒ� Ŭ������ ���� �Ļ��Ǿ�� �Ѵ�.
class ICamera
{
public:
	virtual void Take() = 0;
};

// ����, ���� ī�޶�� ������ ��Ģ�� �ֽ��ϴ�.
// ����ڴ� ��Ģ ��θ� ����ϸ� �˴ϴ�.
class People
{
public:
	void UseCamera(ICamera* p) { p->Take(); }
};

// ���� ī�޶� ���۽ÿ��� "��Ģ��� ����� �˴ϴ�."

class Camera : public ICamera
{
public:
	void Take() { std::cout << "Take Picture" << std::endl; }
};

class HDCamera : public ICamera
{
public:
	void Take() { std::cout << "Take HD Picture" << std::endl; }
};

int main()
{
	People p;
	Camera c;
	p.UseCamera(&c);

	HDCamera hc;
	p.UseCamera(&hc); // ???
}





