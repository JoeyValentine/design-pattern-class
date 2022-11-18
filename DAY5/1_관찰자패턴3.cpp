#include <iostream>
#include <vector>

class Subject;	// ���漱��
				// Ŭ������ ������ ������ ��� ������ ������ ��밡��

struct IGraph
{
	virtual void update(int data) = 0;
	virtual ~IGraph() {}

	// ��� �׷����� �ڽ��� �����ϴ� ����� �˰� �־�� �մϴ�.
	// �׷���, update �뺸�� ������ ��� �����ؼ� ����Ÿ�� ������ �ֽ��ϴ�.
	Subject* subject;
};


class Subject
{
	std::vector<IGraph*> v;
public:
	void attach(IGraph* g) 
	{ 
		v.push_back(g); 
		g->subject = this;
	}

	void detach(IGraph* g) {}
	void notify(int value)
	{
		for (auto g : v)
			g->update(value);
	}
};
//===================================
class Table : public Subject
{
	int data;

	int value[12]{ 1,2,3,4,5,6,7,8,9,10,11,12 }; 
public:
	int* get_value() { return value; }

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
		// ������ ����� ����Ǿ��ٰ� �뺸�� �����Ƿ� 
		// ������ ��� �����ؼ� ����Ÿ�� ������ �;� �մϴ�
		// int* pdata = subject->get_value();

		// subject �� "Subject*" Ÿ���̹Ƿ� 
		// Table ���� ����� �����Ϸ��� "ĳ������ �ʿ�" �մϴ�.
		// �׷��� �̷� ������ ����ϴ� "MFC Doc/View", QT "Model/View"
		// ������ ����ϴ� ���� �׻� ĳ������ ���� �մϴ�.                         
		Table* table = static_cast<Table*>(subject);

		int* pvalue = table->get_value();


		std::cout << "Bar Graph : ";

		for (int i = 0; i < 12; i++)
			std::cout << pvalue[i] << ", ";

		std::cout << "\n";
	}
};




class PieGraph : public IGraph
{
public:
	virtual void update(int data) override
	{
		Table* table = static_cast<Table*>(subject);

		int* pvalue = table->get_value();


		std::cout << "Pie Graph : ";

		for (int i = 0; i < 12; i++)
			std::cout << pvalue[i] << ", ";

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







