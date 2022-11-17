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
int main()
{
	Table table;
	table.edit();
}




int main()
{
}






