/*
힙에 있는 객체에 대한 참조자 반환하기
Prac13에 있는 문제를 해결하는데 있어 TheFunction()의 Green을 힙에 만들면 될 것이다.
TheFunction() 으로부터 반환될 때 Green은 계속 존재할 것이다.
이러한 접근 방식의 문제점은 "Green에 할당된 메모리를 갖고 작업을 마친 뒤 어떤 일이 발생되는가?"" 와 같다
*/
//메모리 누출 발생, 메모리 누출 해결하기

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
	std::cout << "&rGreen:" << &rGreen <<std::endl;
	//다음 메모리를 어떻게 제거할 것인가?
	SimpleCat *pCat = &rGreen;
	delete pCat;
	//이제 rGreen은 무엇을 참조하는가
	return 0;
}

SimpleCat& TheFunction(void)
{
	SimpleCat *pGreen = new SimpleCat(3,5);
	std::cout << "pGreen: " << pGreen << std::endl;

	return *pGreen;//자유 공간의 값을 리턴으로 하여 전달하였다.
}
/*
이 프로그램은 컴파일도 되고, 링크도 된다. 하지만 명백히 부적절한 코드이다.
*/