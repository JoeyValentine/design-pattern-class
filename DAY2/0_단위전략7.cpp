#include <iostream>
#include <vector>

// STL �����̳ʿ� ������ �޸� �Ҵ�� �����
// => �ݵ�� ���Ѿ� �ϴ� ��Ģ�� "C++ǥ�ع���" �� �����Ǿ� �ֽ��ϴ�.
// 1. allocate, deallocate ��� �Լ��� ������ �մϴ�.
// 2. ����Ʈ ������, ���ø� ������, value_type ����� �־�� �մϴ�.
//    => ���������� �ʿ��� �ڵ��..

template<typename T> class debug_alloc
{
public:
	T* allocate(std::size_t sz)
	{
		void* p = malloc(sizeof(T) * sz);
		printf("allocate %d cnts %p\n", sz, p);
		return static_cast<T*>(p);
	}
	void deallocate(T* p, std::size_t sz)
	{
		printf("deallocate %d cnts %p\n", sz, p);
		free(p);
	}

	// �Ʒ� 3���� ����� �ʿ� �մϴ�
	using value_type = T;
	debug_alloc() {}
	template<typename U> debug_alloc(const debug_alloc<U>&) {}
};




int main()
{
	std::vector<int, debug_alloc<int> > v;

	std::cout << "==============" << std::endl;

	v.resize(5); // �Ҵ��� �޸� �Ҵ�

	std::cout << "==============" << std::endl;

	v.resize(10);

	std::cout << "==============" << std::endl;
}