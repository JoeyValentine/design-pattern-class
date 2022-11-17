#include <iostream>
#include <string>
#include <map>

// SRP ( Single Responsibility Principle )
// => 하나의 클래스는 하나의 책임만 부여 하자.

class Image
{
	std::string image_url;

	Image(const std::string& url) : image_url(url)
	{
		std::cout << url << " Downloading..." << std::endl;
	}
public:
	void Draw() { std::cout << "Draw " << image_url << std::endl; }

	friend class ImageFactory;
};


// Image 객체를 생성해서 관리하는 기능을 수행하는 클래스
class ImageFactory
{
	std::map<std::string, Image*> image_map;
public:
	Image* Create(const std::string& url)
	{
		auto ret = image_map.find(url);

		Image* img = nullptr;

		if (ret == image_map.end())
		{
			img = new Image(url);
			image_map[url] = img;
		}
		else
			img = image_map[url];

		return img;
	}
};

int main()
{
	ImageFactory factory;

	Image* img1 = factory.Create("www.naver.com/a.png");
	img1->Draw();

	Image* img2 = factory.Create("www.naver.com/a.png");
	img2->Draw();

}



