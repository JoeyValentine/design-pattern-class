#include <iostream>
#include <vector>
#include <string>

// �Ʒ� main �Լ��� ����ǵ��� File, Folder �ϼ��� ������
// => ������ ��� Ŭ�����̸��� Item ���� �ϼ���
// => �ᱹ PopupMenu, MenuItem ������ ������ ���ϴ�.

class Item
{
	// 1. File, Folder ��� �̸��� �ֽ��ϴ�.
	std::string name; 
public:
	Item(const std::string& name) : name(name) {}
	virtual ~Item() {}

	// 2. File, Folder ��� ũ�⸦ ���Ҽ� �ֽ��ϴ�.
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

	// ������ �ڽŸ��� ũ��� �ֽ��ϴ�.
	// ������ �ڽŸ��� ũ��� ������ ũ�⸦ ���Ҽ� �ֽ��ϴ�.
	std::cout << f2->getSize() <<   std::endl; // 20
	std::cout << fo1->getSize() <<  std::endl; // 10
	std::cout << root->getSize() << std::endl; // 30
}

