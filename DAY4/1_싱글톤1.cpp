#include <iostream>

// 싱글톤 : 오직 한개의 객체만 존재하는 것.
//         프로그램의 어디에서도 동일한 방법으로 접근 가능한것
// => 결국 "전역변수" 와 같습니다.
// => "전역변수" 는 보통 나쁘다고 이야기 합니다.
// => 멀티 스레드에 안전하지 않고, 함수를 독립적으로 분리하기도 어려워집니다.
//========================================================

// 방법 1. 오직한개의 객체가 "static 지역변수"로 만든 모델..
// => "effective-c++" 의 저자인 "scott meyer" 가 처음 제안
// => "meyer's singleton" 이라고 불리는 모델.


class Cursor
{
	// 규칙 1. 생성자를 private !!
private:
	Cursor() { std::cout << "Cursor()" << std::endl; }

	// 규칙 2. 컴파일러가 복사 생성자와 대입연산자를 만들지
	//        않도록해야 한다.
	// => C++11 함수 삭제 문법 사용
	// => 복사 생성자 삭제시 대입연산자도 삭제하는 것이 관례!!
	Cursor(const Cursor&) = delete;
	Cursor operator=(const Cursor&) = delete;				

	// 규칙 3. 오직 한개의 객체를 만들어서 반환하는 static 멤버 함수
public:
	static Cursor& getInstance()
	{
		// static 지역변수
		// 1. 메모리 할당은 컴파일 할때 실행 파일에 .data 섹션에 
		//    할당, 즉, 메모리는 프로세스 실행시 할당
		// 2. 생성자 호출은 이 함수가 처음 호출될때 실행

		// 3. 아래 코드는 멀티스레드 환경에서도 안전합니다.!!
		//    C++11 표준입니다. C++ 표준을 지원하는 모든 컴파일러에서 안전.

		static Cursor instance;



		return instance;
	}
};



int main()
{
	std::cout << "-----------" << std::endl;
//	Cursor& c1 = Cursor::getInstance();
//	Cursor& c2 = Cursor::getInstance();

//	std::cout << &c1 << ", " << &c2 << std::endl;

//	Cursor c3 = c1; // 복사 생성자 사용 하는것도 막아야 한다.


//	Cursor c1, c2; // error
}

