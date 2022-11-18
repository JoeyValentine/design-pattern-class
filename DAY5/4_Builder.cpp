// 2_Builder
#include <iostream>
#include <string>

// 빌더 : 복잡한 객체를 생성하는 방법을 나타내는 패턴
//  => 객체를 생성하는 공정(방법, 순서)은 동일한데
//  => 각 공정의 표현(결과물)이 다를때


// 축구게임 캐릭터를 생각해 봅시다.
// 모자, 유니폼, 신발등을 변경할수 있습니다.
typedef std::string Hat;			// class Hat{}
typedef std::string Uniform;	    // class Uniform{}
typedef std::string Shoes;			// class Shoes{}
typedef std::string Character;		// class Character{}라고 가정

// 캐릭터를 만드는 클래스
class Director
{
public:
	Character construct()
	{
		// 캐릭터를 만드는 공정은 동일 합니다.
		Character c;
		c = c + Hat("야구모자");
		c = c + Uniform파란색("티셔츠");
		c = c + Shoes("운동화");
		return c;
	}
};
int main()
{
	Director d;
	Character c = d.construct();
	std::cout << c << std::endl;

}