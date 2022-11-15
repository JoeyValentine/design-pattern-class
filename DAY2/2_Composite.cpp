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


	// 2. File, Folder ��� ũ�⸦ ���Ҽ� �ֽ��ϴ�.
	virtual int getSize() = 0;
};




class File  
{
public:
};

class Folder 
{
public:
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
	cout << f2->getSize() << endl; // 20
	cout << fo1->getSize() << endl; // 10
	cout << root->getSize() << endl; // 30
}

