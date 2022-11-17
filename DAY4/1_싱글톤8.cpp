#include <iostream>
#include <mutex>

// CRTP ( Curiously Recurring Template Pattern )
// => 기반 클래스 만들때 파생 클래스 이름을 활용할수 있게 하는 기술
// => 파생 클래스가 자신의 이름을 기반 클래스의 템플릿 인자로 전달하는 기술
// => 요즘 오픈소스가 정말 많이 사용하는 "C++ IDioms" 기술

template<typename T> 
class Singleton
{
protected:
	Singleton() { }

	Singleton(const Singleton&) = delete;
	Singleton operator=(const Singleton&) = delete;

	static T* pinstance; // <<==== 1
	static std::mutex mtx;
public:
	static T& getInstance()		// <<====== 2
	{
		std::lock_guard<std::mutex> g(mtx);

		if (pinstance == nullptr)
			pinstance = new T;   // <==== 3
		
		return *pinstance;
	}
};
template<typename T> T* Singleton<T>::pinstance = nullptr;   // <<=== 4
template<typename T> std::mutex Singleton<T>::mtx;


// Mouse 클래스도 "Cursor 처럼 힙에 만드는 싱글톤 모델" 로 하고싶습니다
class Mouse : public Singleton< Mouse  > 
{

};


int main()
{
	Mouse& m1 = Mouse::getInstance();
	Mouse& m2 = Mouse::getInstance();
}

// github.com/aosp-mirror     => 안드로이드 소스 코드 입니다.
//								Android Open Source Project
// 
// platform system core 라는 레포지토리 선택하세요

// libutils/include/utils/singleton.h 파일 확인해 보세요