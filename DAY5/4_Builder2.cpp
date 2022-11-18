// 2_Builder
#include <iostream>
#include <string>

// ���� : ������ ��ü�� �����ϴ� ����� ��Ÿ���� ����
//  => ��ü�� �����ϴ� ����(���, ����)�� �����ѵ�
//  => �� ������ ǥ��(�����)�� �ٸ���


// �౸���� ĳ���͸� ������ ���ô�.
// ����, ������, �Źߵ��� �����Ҽ� �ֽ��ϴ�.
typedef std::string Hat;			// class Hat{}
typedef std::string Uniform;	    // class Uniform{}
typedef std::string Shoes;			// class Shoes{}
typedef std::string Character;		// class Character{}��� ����



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
		// ĳ���͸� ����� ������ �����մϴ�.
		Character c;
		c = c + builder->makeHat();
		c = c + builder->makeUniform();
		c = c + builder->makeShoes();
		return c;
	}
};
// ������ ĳ������ Ư���� ������ ������
class Korean : public IBuilder
{
public:
	virtual Hat makeHat() { return "��"; }
	virtual Uniform makeUniform() { return "�Ѻ�"; }
	virtual Shoes   makeShoes()  { return "¤��"; }
};

class American : public IBuilder
{
public:
	virtual Hat makeHat() { return "�߱�����"; }
	virtual Uniform makeUniform() { return "�纹"; }
	virtual Shoes   makeShoes() { return "����"; }
};
int main()
{
	Korean k;
	American a;

	Director d;
	d.set_builder(&k); // <= ���� ������ �����Ҷ�����
						//   ��ü�� ���� ����


	Character c = d.construct();
	std::cout << c << std::endl;

}