// upcasting2.cpp
#include <vector>

class Animal {};
class Dog : public Animal {};
class Cat : public Animal {};

int main()
{
	std::vector<Dog*>    v1; // Dog ��ü�� �����ϴ� vector
	std::vector<Animal*> v2; // ��� ������ �����ϴ� vector
						
	// Upcasting �� ����(Ȱ��) 1.
	// => ����(��� Ŭ������ ������ Ÿ��)�� �����ϴ� 
	//	  �����̳�(�÷���)�� ����� �ִ�.

}