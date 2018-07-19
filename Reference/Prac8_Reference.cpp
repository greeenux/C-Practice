/*
여러 개의 값을 반환하는 법은 무엇일까?
함수는 한 개의 값만을 반환한다. 두 개의 값을 반환하고 싶을 때는 어떻게 할까?
이 문제를 해결하는 한 가지 방법은, 두 개의 객체를 참조자로 함수에 전달하는 방법이다.
함수는 그 객체를 원하는 값으로 채울 수 있다. 
참조자 전달 방식은 함수로 하여금 그 값을 변화시킬 수 있기 때문에, 이 방법은 실질적으로 함수로 하여금 두 개의 값을 반환하게 해 준다.
이러한 방식은 함수가 원래 return 예약어를 통해 반환하는 값을 다른 목적(오류 코드를 반환하게 하는 등)에 쓸 수 있다.

다시 한 번 말하면 이는 참조자를 사용할 수도, 포인터를 사용할 수도 있다.
*/
//Prac8 과 9는 같이 보고 비교하여 보자.
//포인터로 값을 반환하는 예

#include <iostream>

using namespace std;
short Factor( int n, int *p_Squared, int *p_Cubed);

int main(void)
{
	int number, squared, cubed;
	short error;

	cout << "Enter a number between 0 ~ 20 " << endl;
	cin >> number;

	error = Factor(number, &squared, &cubed);
	if(!error)
	{
		cout << "number : " << number << endl;
		cout << "squared : " << squared << endl;
		cout << "cubed : " << cubed << endl;
	}
	else
		cout << "error occoured" << endl;
	return 0;
}

short Factor(int n, int *p_Sqaured, int *p_Cubed)
{
	short value =0;
	if(n>20)
		value =1;
	else
	{
		*p_Sqaured = n*n;
		*p_Cubed = n*n*n;
		value =0;
	}
	return value;
}
//포인터를 통해 3가지 매개변수를 주어 놓고선 return 을 마치 3가지 하는 것과 같은 느낌을 얻을 수 있다.
//첫째, value의 값이라는 return 둘째, 포인터 방법을 통한 squared의 제곱값 얻기, 셋째, 포인터 방법을 통한 cubed 값 얻어버리기.