/*
점(dot) 연산자를 이용하여 지역적으로 선언된 객체 멤버 자료와 멤버 함수에 접근하였다.
힙의 객체에 접근하려면 포인터를 소환하여야 하므로 포인터에 의해 포인트된 객체에 점 연산자를 사용해야 한다.
좀 복잡해보이는데 다음과 같이 사용된다.
(*pTest).GetAge();
GetAge 가 접근되기 전 먼저 pTest가 소환되게 하기 위해 소괄호가 쓰였다.

이 과정은 좀 따분하므로 C++에서는 포인트 연산자 ->를 사용하여 멤버 변수와 함수에 접근할 수 있도록하였다.
*/
//-> 연산자를 활용하여 힙 객체의 데이터 멤버 접근하기

#include <iostream>

class SimpleCat
{
public:
	SimpleCat(){itsAge=2;} //constructor
	~SimpleCat(){std::cout << "Destructor called"<< std::endl;} //Destructor
	int GetAge() const {return itsAge;}
	void SetAge(int age) {itsAge=age;}
private:
	int itsAge;
};

int main(void)
{
	SimpleCat *Green = new SimpleCat;
	std::cout << "Green is " << Green->GetAge() << "Years Old\n";
	std::cout << "after 5years later\n";
	Green->SetAge(7);
	std::cout << "Green is " << Green->GetAge() << "Years Old\n";
	delete Green;
	return 0;
}