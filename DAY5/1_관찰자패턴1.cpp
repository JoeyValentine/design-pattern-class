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
int main()
{
	Table table;
	table.edit();
}




int main()
{
}






