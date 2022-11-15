#include <iostream>
#include <vector>

// STL 컨테이너에 전달할 메모리 할당기 만들기
// => 반드시 지켜야 하는 규칙이 "C++표준문서" 에 정리되어 있습니다.
// 1. allocate, deallocate 멤버 함수를 만들어야 합니다.
// 2. 디폴트 생성자, 템플릿 생성자, value_type 멤버가 있어야 합니다.
//    => 관례적으로 필요한 코드들..

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

	// 아래 3개의 멤버도 필요 합니다
	using value_type = T;
	debug_alloc() {}
	template<typename U> debug_alloc(const debug_alloc<U>&) {}
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