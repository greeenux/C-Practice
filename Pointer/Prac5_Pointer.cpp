/*
c++은 클래스를 만들고, 그 클래스의 객체에 포인터를 만드는 것을 지원햔다.
객체를 만든 후 그 클래스를 가리키는 포인터를 선언하고, 또 힙에 객체들의 포인터를 저장하는 것을 실습해보도록한다.

예를 들어 다음 문장을 보도록 하자
Cat *pCat = new Cat;
이 호출은 기본 생성자를 스택이나 힙에 만들어내고, 단지 매개변수를 갖지 않는 생성자이다.
생성자는 객체가 만들어지는 어느 곳에서나 호출된다.

힙의 객체를 가리키는 포인터를 삭제하면 객체의 소멸자가 먼저 호출되고 다음에 메모리가 해제된다.
이는 클래스가 깨끗이 정된돌 기회를, 마치 스택에서 객체가 없어지는 것과 마찬가지로 주는 것이다.
*/

//new 와 delete를 이용하여 자유 기억 공간에 객체 생성하기

#include <iostream>

class SimpleCat
{
public:
	SimpleCat();
	~SimpleCat();
private:
	int itsAge;
};

SimpleCat::SimpleCat()
{
	std::cout << "Constructor Called\n";
	itsAge= -1;
}

SimpleCat::~SimpleCat()
{
	std::cout << "Destructor\n";
}

int main(void)
{
	std::cout << "SimpleCat Green called....\n";
	SimpleCat Green;
	std:: cout << "SimpleCat *pTest = new SimpleCat;\n";
	SimpleCat *pTest = new SimpleCat;
	std::cout << "delete pTest.....\n";
	delete pTest;
	std::cout << "Exiting, watch Green go ...\n";
	return 0;
}
/*
잘 살펴보면 객체 Green을 위한 생성자가 호출 되었다.
또한 pTest를 위한 클래스 객체 생성자가 호출 되었으며.
pTest의 객채의 소멸자가 호출 된 다음 메모리의 해제가 이루어 졌으며
마지막으로 Green의 소멸자가 호출되어 끝이난 것을 볼 수 있다.
*/