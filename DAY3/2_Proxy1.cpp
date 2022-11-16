// VC 를 한개 더실행하세요.
// "Server" 프로젝트 여세요
// => 버전 설정하세요
// => 32bit(x86) 으로만 빌드 가능합니다.

#define USING_GUI
#include "cppmaster.h"

int main()
{
	// 1. 서버의 핸들을 얻어 옵니다.
	int server = ec_find_server("Calc");

	std::cout << "서버 번호 : " << server << std::endl;

	// 2. 서버에 명령코드와 파라미터를 전달합니다.
	int n1 = ec_send_server(server, 1, 10, 20);
	int n2 = ec_send_server(server, 2, 10, 20);

	std::cout << n1 << ", " << n2 << std::endl;

}





