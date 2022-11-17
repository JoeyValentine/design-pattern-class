#include <iostream>
#include <string>
#include <map>

class Image
{
	std::string image_url;

	Image(const std::string& url) : image_url(url)
	{
		std::cout << url << " Downloading..." << std::endl;
	}
public:
	void Draw() { std::cout << "Draw " << image_url << std::endl; }


	// Image °´Ã¼¸¦ ¸¸µå´Â "static ¸â¹ö ÇÔ¼ö"
	static Image* Create(const std::string& url)
	{
		Image* img = new Image(url);
		return img;
	}
};


int main()
{
	Image* img1 = Image::Create("www.naver.com/a.png");
	img1->Draw();

	Image* img2 = Image::Create("www.naver.com/a.png");
	img2->Draw();

}



