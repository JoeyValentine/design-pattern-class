// 3_추상팩토리 - 147
#include <iostream>

// 모든 종류의 컨트롤은 공통의 기반 클래스 필요
struct IButton
{
	virtual void Draw() = 0;
	virtual ~IButton() {}
};
struct IEdit
{
	virtual void Draw() = 0;
	virtual ~IEdit() {}
};


struct WinButton : public IButton
{
	void Draw() { std::cout << "Draw WinButton" << std::endl; }
};
struct WinEdit : public IEdit
{
	void Draw() { std::cout << "Draw WinEdit" << std::endl; }
};

struct OSXButton : public IButton
{
	void Draw() { std::cout << "Draw OSXButton" << std::endl; }
};
struct OSXEdit : public IEdit
{
	void Draw() { std::cout << "Draw OSXButton" << std::endl; }
};
//-----------------

// GoF's 의 23개 패턴중에 "Factory" 라는 패턴은 없습니다.
// 대신, "Abstract Factory" 라는 패턴이 있습니다.

// "공장도 인터페이스를 먼저 만들어서 교체 가능하게 하자는 패턴"
// => 객체의 군을 만들기 위한 인터페이스를 정의하지만, 어떤 객체들이 될지는
//    파생 클래스(concreter factory) 가 결정. 
struct IFactory
{
	virtual IButton* CreateButton() = 0;
	virtual IEdit* CreateEdit() = 0;

	virtual ~IFactory() {}
};






//  style 별로 각 콘트롤을 만드는 공장
class WinFactory : public IFactory
{
public:
	IButton* CreateButton() { return new WinButton; }
	IEdit*   CreateEdit()   { return new WinEdit; }
	virtual ~WinFactory() {}
};
class OSXFactory : public IFactory
{
public:
	IButton* CreateButton() { return new OSXButton; }
	IEdit*   CreateEdit() { return new OSXEdit; }
	virtual ~OSXFactory() {}
};
int main(int argc, char** argv)
{
	// 핵심 : 조건에 따라 공장을 변경하게 됩니다.
	//       공장도 인터페이스가 필요 합니다.
	IFactory* factory;

	if (strcmp(argv[1], "-style:OSX") == 0)
		factory = new OSXFactory;
	else
		factory = new WinFactory;

	// 컨트롤이 필요하면 공장을 사용해서 생성
	IButton* btn = factory->CreateButton();
	btn->Draw();
}
// "Day4.exe -style:OSX"










