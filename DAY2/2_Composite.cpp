#include <iostream>
#include <vector>
#include <string>

// 아래 main 함수가 실행되도록 File, Folder 완성해 보세요
// => 공통의 기반 클래스이름은 Item 으로 하세요
// => 결국 PopupMenu, MenuItem 구조와 동일해 집니다.

class Item
{
	// 1. File, Folder 모두 이름이 있습니다.
	std::string name; 
public:
	Item(const std::string& name) : name(name) {}
	virtual ~Item() {}

	// 2. File, Folder 모두 크기를 구할수 있습니다.
	virtual int getSize() = 0;
};

class File : public Item
{
	int size;
public:
	File(const std::string& name, int size)
		: Item(name), size(size) {}

	virtual int getSize() override { return size; }
};

class Folder : public Item
{
	std::vector<Item*> v;
public:
	Folder(const std::string& name) 
		: Item(name) {}

	void addItem(Item* p) { v.push_back(p); }

	virtual int getSize() override 
	{
		int size = 0;

		for (auto p : v)
			size += p->getSize();

		return size;
	}
};



int main()
{
	Folder* root = new Folder("ROOT");
	Folder* fo1  = new Folder("A");
	Folder* fo2  = new Folder("B");
	
	root->addItem(fo1);
	root->addItem(fo2);

	File* f1 = new File("a.txt", 10);
	File* f2 = new File("b.txt", 20);

	fo1->addItem(f1);
	root->addItem(f2);

	// 파일은 자신만의 크기는 있습니다.
	// 폴더는 자신만의 크기는 없지만 크기를 구할수 있습니다.
	std::cout << f2->getSize() <<   std::endl; // 20
	std::cout << fo1->getSize() <<  std::endl; // 10
	std::cout << root->getSize() << std::endl; // 30
}

