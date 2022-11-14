#include <iostream>


// ī�޶�� ī�޶� ����ڸ� ���� �������� ����
// "���Ѿ� �ϴ� ��Ģ(�������̽�)"�� ���� ���� ����.



// �������̽� : ���Ѿ� �ϴ� ��Ģ(���������Լ�)�� ���� ���
// �߻�Ŭ���� : ��Ģ + �ٸ� ����� �ִ� ���

// C++      : ��� ���� �����Լ� ������ ����ؼ� ǥ��
// java, C# : abstract, interface ��� Ű���尡 ������ ����
//==================================================

// ��Ģ : "��� ī�޶�� �Ʒ� Ŭ������ ���� �Ļ��Ǿ�� �Ѵ�." �����������
//		 "��� ī�޶�� �Ʒ� �������̽��� �����ؾ� �Ѵ�" ��� ǥ���մϴ�.

// java, C# : class �� struct �� �� Ÿ�� ���� Ÿ���� Ŀ�ٶ� ��������
// C++ : �� �Ѱ���, ���������� ������ ����Ʈ�� �����ΰ�!! ���ֽ��ϴ�.

//class ICamera // ���������� ������ private �� ����Ʈ
struct  ICamera // ���������� ������ public  �� ����Ʈ
{
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

class UHDCamera : public ICamera
{
public:
	void Take() { std::cout << "Take UHD Picture" << std::endl; }
};


int main()
{
	People p;
	Camera c;
	p.UseCamera(&c);

	HDCamera hc;
	p.UseCamera(&hc); // 

	UHDCamera uhc;		// UHDCamera �� ���߿� �߰��Ǿ�����
	p.UseCamera(&uhc);  // ���� People Ŭ������ �������� �ʰ�
						// ��밡���ϴ�. - "OCP" �� �����Ѵ�!
}





