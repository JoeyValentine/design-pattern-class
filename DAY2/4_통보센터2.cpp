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

	// ���� �Ѱ��� �����ϴ� �뺸 ���͵� �����غ��ô�.
	// "global �뺸����"��� �̸��� ����� ���ô�.
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
	// local �뺸 ����
//	NotificationCenter nc;

	// gloabl �뺸 ����
	NotificationCenter& nc = NotificationCenter::defaultCenter();

	nc.addObserver("LOWBATTERY", &foo);
	nc.addObserver("LOWBATTERY", std::bind(&goo, _1, 0));

	nc.postNotificationWithName("LOWBATTERY", (void*)30);


	// ���� ����
	// poco ��� C++ ��Ʈ��ũ ���̺귯������ �뺸���� ���� ������ �ֽ��ϴ�.
	// �켱������ �����尳���� �ֽ��ϴ�.
	// �츮 �ڵ忡 �߰��� ������
	nc.addObserver("LOWBATTERY", &f1, 1); // 3���� ���ڰ� �켱����
											// Ŭ���� ���� �켱����
	nc.addObserver("LOWBATTERY", &f2, 2, NEWTHREAD);
}



