/*
모든 클래스 멤버 함수들은 숨겨진 매개변수들을 갖고 있는데, 그것은 this라는 포인터이다.
이 포인터는 각 객체를 가리킨다. 따라서 각 GetAge() 나 SetAge()를 호출할 때 그 객체에 대한 this포인터가 숨겨진 매개변수로 포함되어 있다.
*/

#include <iostream>

using namespace std;

class Rectangle
{
public:
	Rectangle();
	~Rectangle();
	void SetLength(int Length)
	{
		this->itsLength= Length;
	}
	int GetLength() const
	{
		return this->itsLength;
	}

	void SetWidth(int Width)
	{
		this->itsWidth=Width;
	}
	int GetWidth(void) const
	{
		return this->itsWidth;
	}

private:
	int itsLength;
	int itsWidth;
};

Rectangle::Rectangle()
{
	itsWidth=5;
	itsLength=10;
}
Rectangle::~Rectangle()
{

}

int main(void)
{
	Rectangle Green;

	cout << "Green's Length is " << Green.GetLength()<<"Feet long\n";
	cout << "Green's Width is " << Green.GetWidth() << "Feet long\n";

	Green.SetWidth(10);
	Green.SetLength(20);

	cout << "Green's Length is " << Green.GetLength()<<"Feet long\n";
	cout << "Green's Width is " << Green.GetWidth() << "Feet long\n";

	return 0;
}
// 객체 그 자체에 대한 포인터를 의미하며, 이 this 포인터는 컴파일러가 알아서 생성과 삭제를 해주기 때문에 걱정할 필요가 없다.