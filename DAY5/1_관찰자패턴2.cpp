#include <iostream>
#include <vector>

struct IGraph
{
	virtual void update(int data) = 0;
	virtual ~IGraph() {}
};
//=======================
// Table �� ����ϴ� ����Ÿ�� ���¿� �������
// ������ ������ �⺻ ������ �׻� ���� �մϴ�.
// ������ ������ �⺻ ������ �����ϴ� ��� Ŭ������ ���� �մϴ�.
// => ������ ���Ͽ��� �� Ŭ������ "subject" ��� �մϴ�.

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







