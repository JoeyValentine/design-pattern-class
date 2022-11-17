#include <iostream>
#include <vector>

struct IGraph
{
	virtual void update(int data) = 0;
	virtual ~IGraph() {}
};
//=======================
// Table 이 취급하는 데이타의 형태에 상관없이
// 관찰자 패턴의 기본 로직은 항상 동일 합니다.
// 관찰자 패턴의 기본 로직을 제공하는 기반 클래스를 설계 합니다.
// => 디자인 패턴에서 이 클래스를 "subject" 라고 합니다.

class Subject
{
	std::vector<IGraph*> v;
public:
	void attach(IGraph* g) { v.push_back(g); }
	void detach(IGraph* g) {}
	void notify(int value)
	{
		for (auto g : v)
			g->update(value);
	}
};

class Table : public Subject
{
	int data;
public:
	void edit()
	{
		while (true)
		{
			std::cout << "input data >> ";
			std::cin >> data;

			notify(data);
		}
	}
};


class BarGraph : public IGraph
{
public:
	virtual void update(int data) override
	{
		std::cout << "Bar Graph : ";

		for (int i = 0; i < data; i++)
			std::cout << "|";

		std::cout << "\n";
	}
};

class PieGraph : public IGraph
{
public:
	virtual void update(int data) override
	{
		std::cout << "Pie Graph : ";

		for (int i = 0; i < data; i++)
			std::cout << ")";

		std::cout << "\n";
	}
};

int main()
{
	Table table;
	BarGraph bg; table.attach(&bg);
	PieGraph pg; table.attach(&pg);
	table.edit();
}







