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
// Image 는 draw 할때만 load 되면 된다.
// 크기 정보등을 얻을때는 그림 파일이 load될 필요 없다.

// 지연된 생성(그릴때 메모리에 load)를 위한 Image 대행자, 
// Proxy 클래스를 만들자
class ImageProxy
{
	Image* img = nullptr;
	std::string filename;
public:
	ImageProxy(const std::string& s) : filename(s) {}
	int get_width() { return 20; } // 파일 헤더 분석해서 얻기

	void draw()
	{
		if (img == nullptr)
			img = new Image(filename);
		img->draw();
	}
};

int main()
{
//	Image img("C:\\dog.png");
	ImageProxy img("C:\\dog.png");
	int w = img.get_width();
//	img.draw();
}