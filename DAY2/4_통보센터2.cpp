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
};

void foo(void* p) { std::cout << "foo : " << std::endl; }
void goo(void* p, int a) { std::cout << "goo : " << std::endl; }


int main()
{
	NotificationCenter nc;

	nc.addObserver("LOWBATTERY", &foo);
	nc.addObserver("LOWBATTERY", std::bind(&goo, _1, 0));

	nc.postNotificationWithName("LOWBATTERY", (void*)30);
}



