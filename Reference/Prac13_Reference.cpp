/*
범위를 벗어난 객체에 대한 참조자를 반환하면 안된다.
일당 c++ 프로그래머가 참조자 전달 방식을 익히면 마구 남용하는 경향이 있다.
물론 지나쳐도 상관은 없지만 참조자는 항상 특정 객체에 대한 다른 이름임을 잊어서는 안 된다.
참조자를 함수에 또는 함수로부터 전달할 때는 항상 다음과 같은 질문을 해야 한다. 
"내가 쓰는 참조자는 무엇을 가리키는가? 그 객체가 지금 존재하는가?"
다음 잘못된 예제를 통해 배워 보자
*/
//존재하지 않은 객체에 대한 참조자 반환

#include <iostream>

class SimpleCat
{
public:
	SimpleCat(int age, int weight);
	~SimpleCat();
	int GetAge() const
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
SimpleCat::SimpleCat(int age, int weight)
{
	itsAge=age;
	itsWeight=weight;
}
SimpleCat::~SimpleCat()
{

}
SimpleCat& TheFunction(void);

int main(void)
{
	SimpleCat &rGreen = TheFunction();
	int age = rGreen.GetAge();
	std:: cout << "rGreen's Age is " << rGreen.GetAge() << std::endl;
	return 0;
}

SimpleCat& TheFunction(void)
{
	SimpleCat Green(3,5);
	return Green;
}