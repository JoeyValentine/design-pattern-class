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

				// �� ������ �Ʒ� 3��ó�� �����մϴ�.
				// 1. Ŀ�� �޸� �Ҵ� : temp = malloc(Cursor)
				// 2. Ŀ�� ������ ȣ�� : Cursor::Cursor()
				// 3. pinstance = temp(�Ҵ�� �޸� �ּ�).

				// �׷���, 2, 3�� ������ �����ϸ� �ӽú�����������
				// ���ϵ� �˴ϴ�. �׷��� ����ȭ �ϸ�
				// 1. Ŀ�� �޸� �Ҵ� : pinstance = malloc(Cursor)
				// 2. Ŀ�� ������ ȣ�� : Cursor::Cursor()
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

