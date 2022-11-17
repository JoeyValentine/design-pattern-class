//1_관찰자패턴1 - 94 page
#include <iostream>
#include <vector>

// 모든 그래프(관찰자, Observer) 의 인터 페이스
struct IGraph
{
	virtual void update(int data) = 0;
	virtual ~IGraph() {}
};

// 관찰의 대상
class Table
{
	int data;	
	std::vector<IGraph*> v; // 관찰자(그래프)를 보관할 컨테이너
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

			// data 가 변경되었으므로 등록된 모든 관찰자에 통보합니다.
			notify(data);
		}
	}
};
//=================
// 관찰자들(Observer)
// IGraph 인터페이스를 구현한 다양한 Chart class 를 제공하면 됩니다.
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
// PieGraph 도 만들어서 붙여 보세요
// => "PieGraph : ))))))))))))" 이렇게 표현해 보세요.






