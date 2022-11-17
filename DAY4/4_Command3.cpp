#include <iostream>
#include <vector>
#include <stack>
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
//==============================

struct ICommand
{
	virtual void execute() = 0;
	virtual bool can_undo() { return false; }
	virtual void undo() { }
	virtual ~ICommand() {}
};

// 생성할 객체가 한개라면
// C++ 진영에서는 "factory method" 보다는 "템플릿"을 사용하는것이
// 편리 합니다.

template<typename T>
class AddCommand : public ICommand
{
	std::vector<Shape*>& v;
public:
	AddCommand(std::vector<Shape*>& v) : v(v) {}

	virtual void execute()  override { v.push_back(new T); }
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
	std::stack<ICommand*> cmd_stack;

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		ICommand* pcmd;

		if (cmd == 1)
		{
			pcmd = new AddCommand<Rect>(v);
			pcmd->execute();
			cmd_stack.push(pcmd);
		}

		else if (cmd == 2)
		{
			pcmd = new AddCommand<Circle>(v);
			pcmd->execute();
			cmd_stack.push(pcmd);
		}
		else if (cmd == 9)
		{
			pcmd = new DrawCommand(v);
			pcmd->execute();
			cmd_stack.push(pcmd);
		}
		else if (cmd == 0)
		{
			if (!cmd_stack.empty())
			{
				pcmd = cmd_stack.top();
				cmd_stack.pop();

				if (pcmd->can_undo())
				{
					pcmd->undo();

					delete pcmd;
				}

			}
		}
	}
}




