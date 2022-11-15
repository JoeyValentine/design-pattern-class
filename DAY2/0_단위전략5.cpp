
// C++ ǥ�� ���̺귯���� STL �� ����
template<typename T, typename Alloc = std::allocator<T> >
class vector
{
	T* buff;
	Alloc ax; // �޸� �Ҵ�� ��ü�� �������Ÿ��!!
			  // ������ ��� ��� �Լ����� �޸��Ҵ�/������ �ʿ��ϸ�
			  // ax �� ��� �Լ� ���
public:
	void resize(int n)
	{
		// ���� ũ�Ⱑ �����ؼ� �ٽ� �Ҵ��Ϸ��� �մϴ�.
		// ��� �Ҵ��ұ�� ?
		// C++������ �޸𸮸� �Ҵ��ϴ� ����� ���� ���� �ֽ��ϴ�.
		// new / malloc / system call / windows api/ Ǯ�� 
		// 
		// buff = new T[n]; // �޸� �Ҵ� ��� ��ü �Ұ����� �ڵ�

		buff = ax.allocate(n);

		// ������ �ʿ��Ҷ��� ax ���
		ax.deallocate(buff, n);
	}
};

