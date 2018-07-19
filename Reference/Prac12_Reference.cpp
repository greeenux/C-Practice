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

const SimpleCat &FunctionTwo(const SimpleCat &Green);

int main(void)
{
	cout <<"making a cat\n";
	SimpleCat green;
	cout << "green is " << green.GetAge()<<endl;
	int age=5;
	green.SetAge(age);
	cout << "green is " << green.GetAge()<<endl;
	cout << "Calling FunctionTwo\n";
	FunctionTwo(green);
	cout<< "green is " ;
	cout << green.GetAge()<<endl;
	return 0;
}

const SimpleCat& FunctionTwo(const SimpleCat &Green)//상수 객체에 참조자 전달하는 FunctionTwo
{
	cout << "Function Two. returning...\n";
	cout << "green is now " << Green.GetAge()<<endl;
	//green->SetAge(7) -> not permitted because const
	return Green;
}
//여기서 중요한 개념은 참조자 그 자신은 다른 객체를 다시 할당할 수 없기 때문에 언제나 상수형이다!!