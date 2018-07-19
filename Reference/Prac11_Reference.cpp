/*
상수 포인터(const pointer)전달하기
값 전달 방식은 박물관에 여러분 소유의 명화 대신 그 명화의 복사본을 게재하는 것과 똑같다. 누군가 손상을 시켜도 원본에 손상이 생기진 않는다.
참조자 전달 방식은 명화가 있는 여러분 집의 주소를 박물관 게시판에 보내는 것과 같고, 그러면 구경꾼들이 집 주소를 보고 들이닥쳐 명화 원본을 감상하다 손상을 입힐 것이다.
그 해결책은 SimpleCat에 상수 포인터를 전달하는 것이다. 이렇게 하면 비상수 메소드가 SimpleCat에 변화를 가하는 것을 막는다.

다음 예제를 통해 살펴보자
*/
// 상수형 포인터 전달, 객체에 포인터 전달하기

#include <iostream>

using namespace std;
class SimpleCat
{
public:
	SimpleCat();
	SimpleCat(SimpleCat&);
	~SimpleCat();

	int GetAge() const
	{
		return itsAge;
	}
	void SetAge(int age)
	{
		itsAge=age;
	}

private:
	int itsAge;
};

SimpleCat::SimpleCat()
{
	cout <<"SimpleCat Constructor\n";
	itsAge=1;
}
SimpleCat::SimpleCat(SimpleCat &)
{
	cout <<"SimpleCat copy Constructor\n";
}
SimpleCat::~SimpleCat()
{
	cout << "Desturctor\n";
}

const SimpleCat *const FunctionTwo(const SimpleCat *const Green);

int main(void)
{
	cout <<"making a cat\n";
	SimpleCat green;
	cout << "green is " << green.GetAge()<<endl;
	int age=5;
	green.SetAge(age);
	cout << "green is " << green.GetAge()<<endl;
	cout << "Calling FunctionTwo\n";
	FunctionTwo(&green);
	cout<< "green is " ;
	cout << green.GetAge()<<endl;
	return 0;
}

const SimpleCat*const FunctionTwo(const SimpleCat *const Green)
{
	cout << "Function Two. returning...\n";
	cout << "green is now " << Green->GetAge()<<endl;
	//green->SetAge(7) -> not permitted because const
	return Green;
}
/*
생성자와 복사 생성자, 소멸자가 그들의 문장을 출력하게끔 정의되었다. 복사 생성자는 호출되지 않았는데, 왜냐하면 객체는 참조자 형태로 전달되었고 따라서 복사본은 만들어지지 않는다.
FunctionTwo는 약간 변화 되었는데, 매개변수와 반환값에서 상수형 객체에 상수형 포인터를 갖고, 또 상수형 객체에 상수형 반환값을 반환한다.
매개 변수와 반환값 모두 참조자로 전달되었으므로 아무런 복사본이 만들어지지 않았으며 복사 생성자도 호출되지 않았다.(매개 변수에서 참조자가 전달된다고 보는 것으로 이해하여야하나, 단지 주소로 주었다고 이해해야 하나 아직 의문이다.)
FunctionTwo()의 포인터는 상수형이고 따라서 비상수형 메소드 SetAge()를 호출할 수 없다.
이 green이라는 비상수형의 객체의 주소가 FunctionTwo()로 전달되었으나 FunctionTwo()의 선언이 포인터를 상수형 객체에 대한 포인터로 선언하였으므로 객체는 상수형처럼 취급된다.
함수로 전달된 객체가 포인터이기 때문에 참조자를 통해 전달할 수 있도록 다음 예제를 통해 쉽게 이해하여 보도록 하자
*/
