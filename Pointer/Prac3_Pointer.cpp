//포인터에는 무엇이 저장되는가~?

#include <iostream>

int main(void)
{
	using namespace std;

	unsigned short int myAge =5, yourAge=10;
	unsigned short int *pAge=&myAge;

	cout << "myAge: \t" << myAge << endl;
	cout << "address of myAge: \t" << &myAge << endl;
	cout << "yourAge: \t" << yourAge << endl;
	cout << "address of yourAge: \t" << &yourAge << endl;
	cout << "Value of pAge:\t " << pAge << endl;
	cout << "deferencing of pAge: \t" << *pAge << endl;
	cout << "address of pAge: \t" << &pAge << endl;

	cout << "changing pointer pAge into yourAge" <<endl;
	pAge = &yourAge;

	cout << "myAge: \t" << myAge << endl;
	cout << "address of myAge: \t" << &myAge << endl;
	cout << "yourAge: \t" << yourAge << endl;
	cout << "address of yourAge: \t" << &yourAge << endl;
	cout << "Value of pAge:\t " << pAge << endl;
	cout << "deferencing of pAge: \t" << *pAge << endl;
	cout << "address of pAge: \t" << &pAge << endl;

	return 0;
}
/*
포인터를 살펴보니 포인터는 어떠한 변수를 가르키는 주소를 담고 있다.
주소를 참조하여 해당하는 주소위치에 바이트를 읽어들인 다음에 값을 출력하는 구조이다.
참고로 거의 모든 포인터를 유효한 주소값이나 널로 초기화하여 사용하도록 하자!
*/