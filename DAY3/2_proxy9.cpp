#include <iostream>
#include <string>

// 그림 파일을 load 해서 그림을 그리는 클래스를 생각해 봅시다.
class Image
{
	std::string filename;
public:
	Image(const std::string& s) : filename(s)
	{
		std::cout << "그림파일을 메모리에 Load" << std::endl;
	}
	void draw() { std::cout << filename << " 그리기" << std::endl; }

	int get_width()
	{
		int w = 20; // get_image_with(filename) 으로 구한다고 가정
		return w;
	}
};
int main()
{
	Image img("C:\\dog.png");
	int w = img.get_width();
	img.draw();
}