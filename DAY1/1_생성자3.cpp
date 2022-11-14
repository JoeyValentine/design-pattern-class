// protected 생성자를 사용하는 이유!!
// => 자신은 객체를 만들수 없지만( 추상적인 존재 )
// => 파생 클래스는 객체를 만들수 있게 하기 위해서 (구체적-concret 존재)

class Animal
{
protected:
	Animal() {}
};
class Dog : public Animal
{
public:
	Dog() {}	// Dog() : Animal() {}	
};
int main()
{
	// 다음중 에러를 모두 골라 보세요
	Animal a;	// error. protected 를 외부에서 호출 안됨
	Dog    d;	// ok. 
}



