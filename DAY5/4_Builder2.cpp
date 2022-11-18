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



struct IBuilder
{
	virtual Hat makeHat() = 0;
	virtual Uniform makeUniform() = 0;
	virtual Shoes   makeShoes() = 0;
	virtual ~IBuilder() {}
};

class Director
{
	IBuilder* builder;
public:
	void set_builder(IBuilder* p) { builder = p; }

	Character construct()
	{
		// 캐릭터를 만드는 공정은 동일합니다.
		Character c;
		c = c + builder->makeHat();
		c = c + builder->makeUniform();
		c = c + builder->makeShoes();
		return c;
	}
};
// 국가별 캐릭터의 특성을 정의한 빌더들
class Korean : public IBuilder
{
public:
	virtual Hat makeHat() { return "갓"; }
	virtual Uniform makeUniform() { return "한복"; }
	virtual Shoes   makeShoes()  { return "짚신"; }
};

class American : public IBuilder
{
public:
	virtual Hat makeHat() { return "야구모자"; }
	virtual Uniform makeUniform() { return "양복"; }
	virtual Shoes   makeShoes() { return "구두"; }
};
int main()
{
	Korean k;
	American a;

	Director d;
	d.set_builder(&k); // <= 국가 선택을 변경할때마나
						//   구체적 빌더 변경


	Character c = d.construct();
	std::cout << c << std::endl;

}