#include <iostream>
#include <mutex>


class Cursor
{
private:
	Cursor() { std::cout << "Cursor()" << std::endl; }

	Cursor(const Cursor&) = delete;
	Cursor operator=(const Cursor&) = delete;

	static Cursor* pinstance;
	static std::mutex mtx;
public:
	// �Ʒ� �Լ��� "100��" ȣ���������� ������ ������
	// => ���� ��ü �����ô� ����ȭ�� �ʿ� ������
	// => ������ 99���� ����ȭ �ʿ� �����ϴ�.
	/*
	static Cursor& getInstance()
	{
		mtx.lock();
		if (pinstance == nullptr)
			pinstance = new Cursor;
		mtx.unlock();

		return *pinstance;
	}
	*/
	// ���� ȣ�� : if ���� �ѹ��̸� �Ǵ� ���� 2ȸ�� ����Ѵ�.
	//           "if �� �߰� ���" ������ �����������
	// ������ ȣ�� : lock/unlock �� ������� �ʱ� ������ ��������.
	
	// "DCLP(Double Check Locking Pattern)" �̶�� �Ҹ��� ���
	// C#, Java ���� ������ �� ������ ��!
	// C++ ������ ���� ������� ������ - ���� �Դϴ�.
	// ( 2004�� �������� �θ� ���Ǿ��µ�, 2004�� ������ ���׶�� ��ǥ)               
	static Cursor& getInstance()
	{
		if (pinstance == nullptr)
		{
			mtx.lock();
		
			if (pinstance == nullptr)
			{
				pinstance = new Cursor;
			}
			
			mtx.unlock();
		}
		return *pinstance;
	}


};
Cursor* Cursor::pinstance = nullptr;
std::mutex Cursor::mtx;


int main()
{
	Cursor& c1 = Cursor::getInstance();
	Cursor& c2 = Cursor::getInstance();

}

