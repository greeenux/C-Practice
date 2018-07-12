/*
const 포인터에 대해 알아보자
예약어 const를 포인터에 쓸 수 있는데 형의 전, 후 또는 양쪽 아무 곳에나 쓸 수 있다. 다음 모두다 문법상으로 맞다.
하지만 상수로 지정되는 내용은 다르다.
const int *pGreen; => 상수형 정수에 대한 포인터이다. 포인트된 값은 변할 수 없다.
int *const pGreen; => 정수형에 대한 상수형 포인터이다. 포인트된 정수값은 바뀔 수 있지만, pGreen은 다른 주소를 가리킬 수 없다.
const int *const pGreen; => 상수형 정수를 가리키는 상수형 포인터이다. 가리키게 되는 값은 바꾸리 수 없고 포인터도 다른 주소를 바꾸어 가리킬 수 없다.
원칙은 const라는 예약어의 바로 오른쪽 항을 상수형으로 보면 된다.
형이 const의 오른쪽에 나오면 저장된 값이 상수형이다.
변수명이 const 오른쪽에 오면 포인터 변수 그 자체가 상수형이다.

함수가 const형으로 선언되었을 때, 함수 안으로부터 객체의 자료를 바꾸려는 어떠한 시도도 컴파일로는 오류를 나타낸다.
포인터를 const 객체로 선언하면, 단지 그 포인터를 호출할 수 있는 메소드는 const 메소드이다.
*/

//상수 메소드를 가진 포인터 이용하기

#include <iostream>

using namespace std;

class Rectangle
{
public:
	Rectangle();
	~Rectangle();
	void SetLength(int length)
	{
		itsLength=length;
	}
	int GetLength(void) const
	{
		return itsLength;
	}
	void SetWidth(int width)
	{
		itsWidth=width;
	}
	int GetWidth(void) const
	{
		return itsWidth;
	}

private:
	int itsLength;
	int itsWidth;
};
Rectangle::Rectangle()
{
	itsWidth=10;
	itsLength=20;
}
Rectangle::~Rectangle()
{

}

int main(void)
{
	Rectangle *pGreen = new Rectangle;
	const Rectangle *pConstGreen = new Rectangle;
	Rectangle *const pConstPtr = new Rectangle;

	cout << "pGreen Width " << pGreen->GetWidth() << "Feet long\n";
	cout << "pConstGreen Width " << pConstGreen->GetWidth() << "Feet long\n";
	cout << "pConstPtr Width " << pConstPtr->GetWidth() << "Feet long\n";

	pGreen->SetWidth(5);
	//pConstGreen->SetWidth(5);
	pConstPtr->SetWidth(5);

	cout << "pGreen Width " << pGreen->GetWidth() << "Feet long\n";
	cout << "pConstGreen Width " << pConstGreen->GetWidth() << "Feet long\n";
	cout << "pConstPtr Width " << pConstPtr->GetWidth() << "Feet long\n";

	delete pGreen;
	delete pConstPtr;
	delete pConstGreen;
	return 0;
}
