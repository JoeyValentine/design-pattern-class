//1_����������1 - 94 page
#include <iostream>
#include <vector>

// ��� �׷���(������, Observer) �� ���� ���̽�
struct IGraph
{
	virtual void update(int data) = 0;
	virtual ~IGraph() {}
};

// ������ ���
class Table
{
	int data;	
	std::vector<IGraph*> v; // ������(�׷���)�� ������ �����̳�
public:
	void attach(IGraph* g) { v.push_back(g); }
	void detach(IGraph* g) {}
	void notify(int value)
	{
		for (auto g : v)
			g->update(value);
	}
	void edit()
	{
		while (true)
		{
			std::cout << "input data >> ";
			std::cin >> data;

			// data �� ����Ǿ����Ƿ� ��ϵ� ��� �����ڿ� �뺸�մϴ�.
			notify(data);
		}
	}
};
//=================
// �����ڵ�(Observer)
// IGraph �������̽��� ������ �پ��� Chart class �� �����ϸ� �˴ϴ�.
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
// PieGraph �� ���� �ٿ� ������
// => "PieGraph : ))))))))))))" �̷��� ǥ���� ������.






