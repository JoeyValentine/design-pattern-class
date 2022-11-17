#include <iostream>
#include <string>
#include <map>

// 싱글톤     : static 멤버 함수로 객체 생성
//			 => "한개만 생성" 하자
// 
// Flyweight : static 멤버 함수로 객체 생성(다른 방법도 가능)
//			=> "여러개 생성할수 있는데"
//          => "속성이 같은 객체는 공유할수 있게 하자."



class Image
{
	std::string image_url;

	Image(const std::string& url) : image_url(url)
	{
		std::cout << url << " Downloading..." << std::endl;
	}
public:
	void Draw() { std::cout << "Draw " << image_url << std::endl; }


	// Image 객체를 만드는 "static 멤버 함수"
	static Image* Create(const std::string& url)
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
	static std::map<std::string, Image*> image_map;
};
std::map<std::string, Image*> Image::image_map;


int main()
{
	// IOS( cocoa 라이브러리) 에 있는 "UIImage" 클래스가 
	// 객체 생성시 아래 처럼 "static 멤버함수"로 생성합니다.
	Image* img1 = Image::Create("www.naver.com/a.png");
	img1->Draw();

	Image* img2 = Image::Create("www.naver.com/a.png");
	img2->Draw();

}



