// 6_Mediator - 중재자 패턴 
#include <iostream>

// 객체간의 상호 관계가 복잡하면
// => 중재자를 도입해라.
// => M:N 의 관계를 1:N 의 관계로 변경








class CheckBox
{
	bool state;
public:
	CheckBox() : state(false) {}
	
	void SetCheck(bool b) { state = b; ChangeState(); }
	bool GetCheck()       { return state; }

	virtual void ChangeState() {}
};



class RadioBox
{
	bool state;
public:
	RadioBox() : state(false) {}
	
	void SetCheck(bool b) { state = b; ChangeState(); }
	bool GetCheck()       { return state; }

	virtual void ChangeState() {}
};

int main()
{
}



