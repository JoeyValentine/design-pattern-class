#include <iostream>
#include <string>
#include <map>

// �̱���     : static ��� �Լ��� ��ü ����
//			 => "�Ѱ��� ����" ����
// 
// Flyweight : static ��� �Լ��� ��ü ����(�ٸ� ����� ����)
//			=> "������ �����Ҽ� �ִµ�"
//          => "�Ӽ��� ���� ��ü�� �����Ҽ� �ְ� ����."



class Image
{
	std::string image_url;

	Image(const std::string& url) : image_url(url)
	{
		std::cout << url << " Downloading..." << std::endl;
	}
public:
	void Draw() { std::cout << "Draw " << image_url << std::endl; }


	// Image ��ü�� ����� "static ��� �Լ�"
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
	// IOS( cocoa ���̺귯��) �� �ִ� "UIImage" Ŭ������ 
	// ��ü ������ �Ʒ� ó�� "static ����Լ�"�� �����մϴ�.
	Image* img1 = Image::Create("www.naver.com/a.png");
	img1->Draw();

	Image* img2 = Image::Create("www.naver.com/a.png");
	img2->Draw();

}



