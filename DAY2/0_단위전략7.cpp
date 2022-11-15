#include <iostream>
#include <vector>

// STL 컨테이너에 전달할 메모리 할당기 만들기
// => 반드시 지켜야 하는 규칙이 "C++표준문서" 에 정리되어 있습니다.
// 1. allocate, deallocate 멤버 함수를 만들어야 합니다.

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
};




int main()
{
	std::vector<int, debug_alloc<int> > v;

	std::cout << "==============" << std::endl;

	v.resize(5); // 할당기로 메모리 할당

	std::cout << "==============" << std::endl;

	v.resize(10);

	std::cout << "==============" << std::endl;
}