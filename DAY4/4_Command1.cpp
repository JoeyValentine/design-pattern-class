#include <iostream>
#include <vector>
#include "Helper.h"

class Shape
{
public:
	virtual void draw() = 0;
	virtual ~Shape() {}
};

class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }
};
class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }
};
// undo/redo 기능을 넣어 봅시다.

// 모든 명령의 인터페이스
struct ICommand
{
	virtual void execute() = 0;
	virtual bool can_undo() { return false; }
	virtual void undo() { }
	virtual ~ICommand() {}
};

// 사각형을 추가하는 명령
class AddRectCommand : public ICommand
{
	std::vector<Shape*>& v;
public:
	AddRectCommand(std::vector<Shape*>& v) : v(v) {}

	virtual void execute()  override { v.push_back(new Rect); }
	virtual bool can_undo() override { return true; }
	virtual void undo()     override 
	{
		Shape* p = v.back();
		v.pop_back();
			
		delete p;	
	}
};


class AddCircleCommand : public ICommand
{
	std::vector<Shape*>& v;
public:
	AddCircleCommand(std::vector<Shape*>& v) : v(v) {}

	virtual void execute()  override { v.push_back(new Circle); }
	virtual bool can_undo() override { return true; }
	virtual void undo()     override
	{
		Shape* p = v.back();
		v.pop_back();

		delete p;
	}
};

class DrawCommand : public ICommand
{
	std::vector<Shape*>& v;
public:
	DrawCommand(std::vector<Shape*>& v) : v(v) {}

	virtual void execute()  override 
	{
		for (auto p : v)
			p->draw();
	}
	virtual bool can_undo() override { return true; }
	virtual void undo()     override { system("cls"); }
};



int main()
{
	std::vector<Shape*> v;

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		ICommand* pcmd;

		if (cmd == 1)
		{
			pcmd = new AddRectCommand(v); // 사각형을 추가하는 일을
										// 하는 명령객체를 생성해서
			pcmd->execute();
		}

		else if (cmd == 2)
		{
			pcmd = new AddCircleCommand(v);
			pcmd->execute();
		}
		else if (cmd == 9)
		{
			pcmd = new DrawCommand(v);
			pcmd->execute();
		}
	}
}




