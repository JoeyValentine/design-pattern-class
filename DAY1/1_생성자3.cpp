// protected �����ڸ� ����ϴ� ����!!
// => �ڽ��� ��ü�� ����� ������( �߻����� ���� )
// => �Ļ� Ŭ������ ��ü�� ����� �ְ� �ϱ� ���ؼ� (��ü��-concret ����)

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
	// ������ ������ ��� ��� ������
	Animal a;	// error. protected �� �ܺο��� ȣ�� �ȵ�
	Dog    d;	// ok. 
}



