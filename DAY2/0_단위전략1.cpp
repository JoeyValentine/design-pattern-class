template<typename T> class List
{
	// 다양한 멤버 데이터들.. 
public:
	void push_front(const T& a)
	{
		// mutex.lock()
		//......
		// mutex.unlock();
	}
};
List<int> st; // 전역변수는 멀티스레드에 안전하지 않습니다.

int main()
{
	// mutex.lock();
	st.push_front(10);
	// mutex.unlock();
}
