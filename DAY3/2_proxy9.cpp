#include <iostream>
#include <string>

// �׸� ������ load �ؼ� �׸��� �׸��� Ŭ������ ������ ���ô�.
class Image
{
	std::string filename;
public:
	Image(const std::string& s) : filename(s)
	{
		std::cout << "�׸������� �޸𸮿� Load" << std::endl;
	}
	void draw() { std::cout << filename << " �׸���" << std::endl; }

	int get_width()
	{
		int w = 20; // get_image_with(filename) ���� ���Ѵٰ� ����
		return w;
	}
};
// Image �� draw �Ҷ��� load �Ǹ� �ȴ�.
// ũ�� �������� �������� �׸� ������ load�� �ʿ� ����.

// ������ ����(�׸��� �޸𸮿� load)�� ���� Image ������, 
// Proxy Ŭ������ ������
class ImageProxy
{
	Image* img = nullptr;
	std::string filename;
public:
	ImageProxy(const std::string& s) : filename(s) {}
	int get_width() { return 20; } // ���� ��� �м��ؼ� ���

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