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

class People
{
public:
	void Use(IMP3* p)	// 약한 결합, 교체 가능한 설계
	{					// 다양한 "MP3 제품" 사용할수 있다.
		p->Play();
		p->Stop();

		// 그런데, 사용자가 1분 미리 듣기 기능을 요구한다!!
		// 다른 제품으로 교체는 쉽지만!!
		// => 기능의 추가(변경, update) 는 어렵다.
		// => 인터페이스를 변경하는 것은 너무나 어렵다!!
		p->PlayOneMinute();
	}
};



int main()
{
	People p;
	IPod pod;
	p.Use(&pod);
}


