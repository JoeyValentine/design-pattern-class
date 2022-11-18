// 8_�޸��� - 178
#include <iostream>
#include <vector>
#include <map>

class Graphics
{
	// ��ü�� ��� ����Ÿ�� ����Ǿ�� �ϴ� ����
	// ������ Ÿ������ ����
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

	int token = g.Save();	// ĸ��ȭ�� ���� ���� �ʰ�
							// ��ü�� ���¸� �����ߴٰ� 
							// ���� �Ҽ� �ְ��Ѵ�.

	g.SetStrokeColor(1);
	g.SetStrokeWidth(20);
	g.DrawLine(0, 0, 300, 300);
	g.DrawLine(0, 0, 400, 400);

	// ó���� �׷ȴ� ���� �����ϰ� �׸��� �ʹ�.
	g.Restore(token);
	g.DrawLine(0, 0, 300, 300);
	g.DrawLine(0, 0, 400, 400);
}









