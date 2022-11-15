// Callback정리
// 1. 객체가 한개의 이벤트만 발생할때
// => MenuItem 은 "선택" 시 해야할 일만 있다.

// => 객체에 "인터페이스"가 아닌 "함수(주소)"만 등록하는것이 편리한 경우가 많습니다.

// => cocoa(IOS) 라이브러리에서는 "target - action" 기술이라고 부릅니다.

// 2. 객체가 여러가지의 이벤트를 발생할때
// => 각각의 함수를 따로 등록하면은 관리하기가 복잡해 집니다.
// => 이경우 "인터페이스"를 설계하고, 객체를 등록하는것이 편리합니다.
// => 각 이벤트에 대응하는 함수이름이 약속됩니다.
// => Listener 방식
// => cocoa(IOS) 라이브러리에서 "delegate"  패턴이라고 부릅니다.

struct ISensorListener
{
	virtual void Fail() = 0;
	virtual void Update(int n) = 0;
};

class MyHandler : public ISensorListener {   };

MyHandler h;
sensor.add_listener(&h);

