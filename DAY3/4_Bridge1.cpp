// 6_Bridge1 - 90 page
#include <iostream>

// ��� "MP3 Player" �� ���Ѿ��ϴ� ��Ģ�� ���� �Ѵ�.
struct IMP3
{
	virtual void Play() = 0;
	virtual void Stop() = 0;
	virtual ~IMP3() {}
};

class IPod : public IMP3
{
public:
	void Play() { std::cout << "Play MP3 with IPod" << std::endl; }
	void Stop() { std::cout << "Stop" << std::endl; }
};

class People
{
public:
	void Use(IMP3* p)	// ���� ����, ��ü ������ ����
	{					// �پ��� "MP3 ��ǰ" ����Ҽ� �ִ�.
		p->Play();
		p->Stop();

		// �׷���, ����ڰ� 1�� �̸� ��� ����� �䱸�Ѵ�!!
		// �ٸ� ��ǰ���� ��ü�� ������!!
		// => ����� �߰�(����, update) �� ��ƴ�.
		// => �������̽��� �����ϴ� ���� �ʹ��� ��ƴ�!!
		p->PlayOneMinute();
	}
};



int main()
{
	People p;
	IPod pod;
	p.Use(&pod);
}


