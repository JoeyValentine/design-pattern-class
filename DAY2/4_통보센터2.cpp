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
		for (auto f : notif_map[key])
			f(hint);
	}

	// 오직 한개만 존재하는 통보 센터도 생각해봅시다.
	// "global 통보센터"라는 이름을 사용해 봅시다.
	static NotificationCenter& defaultCenter()
	{
		static NotificationCenter instance;
		return instance;
	}
};

void foo(void* p) { std::cout << "foo : " << std::endl; }
void goo(void* p, int a) { std::cout << "goo : " << std::endl; }


int main()
{
	// local 통보 센터
//	NotificationCenter nc;

	// gloabl 통보 센터
	NotificationCenter& nc = NotificationCenter::defaultCenter();

	nc.addObserver("LOWBATTERY", &foo);
	nc.addObserver("LOWBATTERY", std::bind(&goo, _1, 0));

	nc.postNotificationWithName("LOWBATTERY", (void*)30);
}



