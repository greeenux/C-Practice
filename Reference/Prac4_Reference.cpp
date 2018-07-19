/*
무엇이 참조될 수 있을까?
사용자가 정의한 객체를 포함하여 아무 객체나 참조될 수 없다. 참조자를 크랠스가 아니라 객체에 대해 만들 수 있음에 주목하자
객체에 대한 참조자는 객체 그 자체처럼 사용된다.
멤버 자료와 메소드는 클래스 멤버 접근 연산자를 사용하여 접근될 수 있다.
그리고 참조자는 그 개게에 대해 다른 이름으로 사용된다.
*/

//클래스 객체 참조하기

#include <iostream>

class SimpleCat
{
public:
	SimpleCat(int age, int weight);
	~SimpleCat(){}
	int GetAge()
	{
		return itsAge;
	}
	int GetWeight()
	{
		return itsWeight;
	}

private:
	int itsAge;
	int itsWeight;
};
SimpleCat::SimpleCat(int age,int weight)
{
	itsAge=age;
	itsWeight=weight;
}

int main(void)
{
	SimpleCat Green(10,5);
	SimpleCat &r_Green=Green;

	std::cout << "Green is : " << Green.GetAge() << "years old " << std::endl;
	std::cout << "Green is : " << r_Green.GetWeight() << "kilo" << std::endl;

	return 0;
}