//참조자를 활용하여 함수로부터 복수 개의 값을 전달받기

#include <iostream>

using namespace std;
typedef unsigned short USHORT;
enum ERR_CODE {SUCCESS, ERROR}; // 0일시 성공, 1 일시 실패

ERR_CODE Factor (USHORT n, USHORT &r_squared,USHORT &r_cubed);
//다음과 같이 써도 무방하다ERR_CODE Factor (USHORT n, USHORT &r_suqared,USHORT &r_cubed);//선언부분이기 때문에
int main(void)
{
	USHORT number ,squared, cubed;
	ERR_CODE result;

	cout << "Enter a number between 0 ~ 20 " << endl;
	cin >> number;

	result = Factor(number, squared, cubed);
	
	if (result ==SUCCESS)
	{
		cout << "number : " << number << endl;
		cout << "squared : " << squared << endl;
		cout << "cubed : " << cubed << endl;
	}
	else
		cout << "Error " << endl;

	return 0;
}
ERR_CODE Factor(USHORT n, USHORT &r_squared, USHORT &r_cubed)
{
	if(n>20)
	{
		return ERROR;
	}
	else
	{
		r_squared = n*n;
		r_cubed = n*n*n;
		return SUCCESS;
	}
}
