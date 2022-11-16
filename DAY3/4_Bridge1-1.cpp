// 6_Bridge1 - 90 page
#include <iostream>

// 모든 "MP3 Player" 가 지켜야하는 규칙을 설계 한다.
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
// IMP3 를 직접 사용하게 하지말고
// 추상 계층을 제공하고, 사용자는 추상 계층만 사용하게 한다.
class MP3Player
{
	IMP3* engine;
public:
	MP3Player(IMP3* p = nullptr) : engine(p)
	{
		if (p != nullptr)
			engine = new IPod;
	}
	// 추상 계층은 모든 기능을 구현 계층에 의존하게 됩니다.
	void Play() { engine->Play(); }
	void Stop() { engine->Stop(); }
};
//--------------------------------------------------
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


