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

	// 구현부(IMP3) 를 변경하지 않고 추상 계층만 변경해서
	// 새로운 서비스 제공!!
	void PlayOneMinute()
	{
		engine->Play();
		// 1분후..
		engine->Stop();
	}
};
//--------------------------------------------------
// 이제 프로그램 내부에서 MP3가 필요하면 "추상계층인 MP3Player"만 사용합니다.
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


// Bridge 패턴
// => "구현(IMP3) 와 추상(MP3Player) 를 분리해서 상호 독립적인 update 가 
//    가능하게 하는 패턴!