// CalcProxy.cpp
#define USING_GUI
#include "cppmaster.h"
#include "ICalc.h"

class Calc : public ICalc
{
	int server;
public:
	Calc() { server = ec_find_server("Calc"); }

	int Add(int a, int b) { return ec_send_server(server, 1, a, b); }
	int Sub(int a, int b) { return ec_send_server(server, 2, a, b); }
};

// 동적모듈을 사용하는 client 는 동적 모듈내의 proxy 클래스 이름을
// 알지도 못하고, 알필요도 없고, 알아도 안됩니다.
// => 동적 모듈 내부에서 Proxy 객체의 생성을 제공해야 합니다.
extern "C" __declspec(dllexport)
ICalc* Create()
{
	return new Calc;
}
//===============================
// 빌드 하는 법
// => 윈도우 시작 버튼 => Visual Studio 폴더 선택
// => 개발자 명령 프롬프트 실행(comand prompt for developer)
// => 소스가 있는 폴더로 이동후
// 
// cl CalcProxy.cpp /LD /link user32.lib gdi32.lib kernel32.lib

// D:      => D 드라이브 이동
// cd 폴더  => 폴더로 이동
// cd ..   => 상위 폴더이동.


