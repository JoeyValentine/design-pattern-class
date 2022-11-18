// 6_Mediator - ������ ���� 
#include <iostream>

// ��ü���� ��ȣ ���谡 �����ϸ�
// => �����ڸ� �����ض�.
// => M:N �� ���踦 1:N �� ����� ����








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



