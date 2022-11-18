#include <iostream>
#include <vector>

class Subject;	// 전방선언
				// 클래스의 완전한 선언이 없어도 포인터 변수는 사용가능

struct IGraph
{
	virtual void update(int data) = 0;
	virtual ~IGraph() {}

	// 모든 그래프는 자신이 관찰하는 대상을 알고 있어야 합니다.
	// 그래서, update 통보시 관찰에 대상에 접근해서 데이타를 얻을수 있습니다.
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
		// 관찰이 대상이 변경되었다고 통보가 왔으므로 
		// 관찰에 대상에 접근해서 데이타를 가지고 와야 합니다
		// int* pdata = subject->get_value();

		// subject 는 "Subject*" 타입이므로 
		// Table 고유 멤버에 접근하려면 "캐스팅이 필요" 합니다.
		// 그래서 이런 구조를 사용하는 "MFC Doc/View", QT "Model/View"
		// 구조를 사용하다 보면 항상 캐스팅이 등장 합니다.                         
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







