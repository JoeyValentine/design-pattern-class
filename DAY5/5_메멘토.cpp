// 8_메멘토 - 178
#include <iostream>


// 화면에 그림을 그릴때 사용하는 클래스
class Graphics
{
	// 수백가지의 그리는 함수를 제공합니다.
}

int main()
{
	Graphics g;
	g.DrawLine(0, 0, 100, 100);

	// 선의 색상이나 두께 등을 변경하고 싶습니다.

	// 방법 1. DrawLine()의 인자로 전달하자.
	// => windows api gdi+
	g.DrawLine(0, 0, 100, 100, red, 10);
	g.DrawLine(0, 0, 100, 100, red, 10);

	// 방법 2. Graphics 객체의 속성값으로 관리하자
	// => windows api gdi
	// => IOS 의 cocoa 라이브러리 
	g.SetStrokeColor(red);
	g.SetStrokeWidth(10);
	g.SetStrokeStype(DASH);
	g.DrawLine(0, 0, 100, 100); // 위에서 지정한 Stroke 속성값 사용
	g.DrawLine(0, 0, 100, 100);
}









