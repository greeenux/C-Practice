/*
하나 이상의 멤버 자료가 자유 기억 공간의 객체를 가리키는 포인터가 될 수 있다. 이 메모리는 클래스의 생성자나 혹은 그 메소드 안에서 할당될 수 있으며, 클래스의 소멸자 안에서 삭제될 수 있다.
*/

//멤버 연산자로서의 포인터
//->연산자로 접근되는 데이터 멤버로서의 포인터

#include <iostream>

class SimpleCat
{
public:
	SimpleCat();
	~SimpleCat();
	int GetAge() const{return *itsAge;}
	void SetAge(int age) {*itsAge=age;}

	int GetWeight() const{return *itsWeight;}
	void SetWeight(int weight) {*itsWeight = weight;}

private:
	int *itsAge;
	int *itsWeight;
};
SimpleCat::SimpleCat()
{
	itsAge = new int(2); //클래스 자체에서 선언이 된 private 포인터 변수이므로 여기서는 할당을 해준다.
	itsWeight = new int(10);//이렇게 하면 힙에 정수형 변수를 생성하고 값을 초기화하게 된다. 
}
SimpleCat::~SimpleCat()
{
	delete itsAge;
	delete itsWeight;
}

int main(void)
{
	SimpleCat *Green = new SimpleCat;
	std::cout << "Green is " << Green->GetAge() << "years old \n";
	std::cout << "Green is " << Green->GetWeight() << "kilo \n";
	Green->SetAge(5);Green->SetWeight(8);
	std::cout << "After 3 years later\n\n";
	std::cout << "Green is " << Green->GetAge() << "years old \n";
	std::cout << "Green is " << Green->GetWeight() << "kilo \n";
	delete Green;
	return 0;
}