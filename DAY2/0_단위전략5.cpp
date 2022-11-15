
// C++ 표준 라이브러리인 STL 의 원리
template<typename T, typename Alloc = std::allocator<T> >
class vector
{
	T* buff;
	Alloc ax; // 메모리 할당기 객체를 멤버데이타로!!
			  // 앞으로 모든 멤버 함수에서 메모리할당/해지가 필요하면
			  // ax 의 멤버 함수 사용
public:
	void resize(int n)
	{
		// 버퍼 크기가 부족해서 다시 할당하려고 합니다.
		// 어떻게 할당할까요 ?
		// C++에서는 메모리를 할당하는 방법이 아주 많이 있습니다.
		// new / malloc / system call / windows api/ 풀링 
		// 
		// buff = new T[n]; // 메모리 할당 방식 교체 불가능한 코드

		buff = ax.allocate(n);

		// 해지가 필요할때도 ax 사용
		ax.deallocate(buff, n);
	}
};

