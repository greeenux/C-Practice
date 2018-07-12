//포인터를 사용한 자료 연산

#include <iostream>

typedef unsigned short int USHORT;

int main(void)
{
	using std::cout;
	USHORT myAge;
	USHORT *pAge=0; //declare with Null Pointer

	myAge=5;

	cout << "myAge : " << myAge << std::endl;
	pAge=&myAge;
	cout << "*pAge : " << *pAge << "\n";

	cout << "\nSetting *pAge = 9 " << "\n";
	*pAge=7;

	cout << "myAge : " << myAge << std::endl;
	cout << "*pAge : " << *pAge << "\n";

	return 0;
}
/* 
위와 같이 간접 지정 연산자 (*) = 조회 연산자 를 통해서 주소의 저장된 값을 간접적으로 참조하여 값을 변경하는 연습을 할 수 있다.
*/