#include <iostream>
#include <string>
#include <map>
#include <functional>
#include <vector>
using namespace std::placeholders;


class NotificationCenter
{
	using HANDLER = std::function<void(void*)>;

	std::map<std::string, std::vector<HANDLER>> notif_map;

public:
	void addObserver(const std::string& key, HANDLER handler)
	{
		notif_map[key].push_back(handler);
	}

	void postNotificationWithName(const std::string& key, void* hint)
	{
		for (auto f : notif_map[key] )
			f(hint);
	}
};

void foo(void* p)        { std::cout << "foo : " << std::endl; }
void goo(void* p, int a) { std::cout << "goo : " << std::endl; }


int main()
{
	// IOS 라이브러이에는 "통보센터" 라는 도구가 있습니다.
	NotificationCenter nc;

	nc.addObserver("LOWBATTERY", &foo);
	nc.addObserver("LOWBATTERY", std::bind(&goo, _1, 0) );

	nc.addObserver("DISCONNECTWIFI", &foo);

	// 배터리 모듈쪽에서 배터리가 부족해지면
	nc.postNotificationWithName("LOWBATTERY", (void*)30);
}

// 중재자(Mediator) 패턴
// => 여러개의 객체가 존재하고,
// => 객체간의 상호 관계가 복잡하면
// => 중재자를 사용해라
// => 객체간의 M:N 의 관계를 
// => 객체와 중재자간의 N:1의 관계로 변경하는 패턴


