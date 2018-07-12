//변수의 주소를 보여줌
//주소 연산자와 지역 변수 주소를 사용하는 예

#include <iostream>

int main(void)
{
	using namespace std;
	
	unsigned long longFirst =88;
	unsigned long longVar = 65535;
	unsigned short shortVar =5;
	long lVar = -65535;
	char *pSizeOfChar =0;
	char test ='a';
	pSizeOfChar = &test;

	cout << "longFirst: \t\t" << longFirst;
	cout << "\tAddress of longFirst: \t";
	cout << &longFirst << endl;

	cout << "longVar: \t" << longVar;
	cout << "\tAddress of longVar: \t";
	cout << &longVar << endl;


	cout << "shortVar: \t\t" << shortVar;
	cout << "\tAddress of shortVar: \t";
	cout << &shortVar << endl;


	cout << "lVar: \t\t" << lVar;
	cout << "\tAddress of lVar : \t\t";
	cout << &lVar << endl;
	cout << sizeof(pSizeOfChar)<< endl;
	return 0;
}
/*
Address의 크기가 컴퓨터 마다 다르지만 64비트 프로세서 또는 운영체제 기반에서는
메모리의 주소가 8씩 스택에 할당하는 것을 생각해 볼 수 있다. 32bit 일 때도 유사할 것이다. 고민해보자.
스택 <높은 주소>
longFirst	(expected 8 space occupied)
longVar		(expected 8 space occupied)
shortVar	(expected 2 space occupied)--->
lVar 		(expected 8 space occupied)---> these two values occupy 16 memory space(stack) for 64bit operating systems.
스택 <낮은 주소> 

마지막 예시에서 역시 64비트 운영체제라면 => 컴파일러가 sizeof(pSizeOfChar)의 포인터 크기를 8로 돌려줄 것이다. 32비트 운영체제 또는 프로세서에서는 포인터의 크기가 4바이트일 것이다
*/