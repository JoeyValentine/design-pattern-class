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
int main()
{
	Image img("C:\\dog.png");
	int w = img.get_width();
	img.draw();
}