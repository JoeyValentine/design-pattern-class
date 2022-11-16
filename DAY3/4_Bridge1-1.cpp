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
//===================================
// IMP3 �� ���� ����ϰ� ��������
// �߻� ������ �����ϰ�, ����ڴ� �߻� ������ ����ϰ� �Ѵ�.
class MP3Player
{
	IMP3* engine;
public:
	MP3Player(IMP3* p = nullptr) : engine(p)
	{
		if (p != nullptr)
			engine = new IPod;
	}
	// �߻� ������ ��� ����� ���� ������ �����ϰ� �˴ϴ�.
	void Play() { engine->Play(); }
	void Stop() { engine->Stop(); }

	// ������(IMP3) �� �������� �ʰ� �߻� ������ �����ؼ�
	// ���ο� ���� ����!!
	void PlayOneMinute()
	{
		engine->Play();
		// 1����..
		engine->Stop();
	}
};
//--------------------------------------------------
// ���� ���α׷� ���ο��� MP3�� �ʿ��ϸ� "�߻������ MP3Player"�� ����մϴ�.
class People
{
public:
	void Use(MP3Player* p)
	{				
		p->Play();
		p->Stop();

		p->PlayOneMinute();
	}
};



int main()
{
	People p;
	IPod pod;
	p.Use(&pod);
}


// Bridge ����
// => "����(IMP3) �� �߻�(MP3Player) �� �и��ؼ� ��ȣ �������� update �� 
//    �����ϰ� �ϴ� ����!