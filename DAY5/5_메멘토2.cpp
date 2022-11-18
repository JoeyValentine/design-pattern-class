// 8_메멘토 - 178
#include <iostream>
#include <vector>
#include <map>

class Graphics
{
	// 객체의 멤버 데이타중 저장되어야 하는 것을
	// 별도의 타입으로 설계
	struct Memento
	{
		int penWidth;
		int penColor;
	};
	std::map<int, Memento*> memento_map;

	int penWidth = 1;
	int penColor = 0;
	int temporary_data;
public:
	int Save()
	{
		static int key = 0;
		++key;
		Memento* m = new Memento;
		m->penColor = penColor;
		m->penWidth = penWidth;
		memento_map[key] = m;
		return key;
	}
	void Restore(int key)
	{
		Memento* p = memento_map[key];
		penColor = p->penColor;
		penWidth = p->penWidth;
	}



	void DrawLine(int x1, int y1, int x2, int y2)
	{
	}
	void SetStrokeColor(int c) { penColor = c; }
	void SetStrokeWidth(int w) { penWidth = w; }
};

int main()
{
	Graphics g;

	g.SetStrokeColor(0);
	g.SetStrokeWidth(10);
	g.DrawLine(0, 0, 100, 100);
	g.DrawLine(0, 0, 200, 200); 

	int token = g.Save();	// 캡슐화를 위배 하지 않고
							// 객체의 상태를 저장했다가 
							// 복구 할수 있게한다.

	g.SetStrokeColor(1);
	g.SetStrokeWidth(20);
	g.DrawLine(0, 0, 300, 300);
	g.DrawLine(0, 0, 400, 400);

	// 처음에 그렸던 선과 동일하게 그리고 싶다.
	g.Restore(token);
	g.DrawLine(0, 0, 300, 300);
	g.DrawLine(0, 0, 400, 400);
}









