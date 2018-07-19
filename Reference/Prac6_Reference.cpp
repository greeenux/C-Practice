//포인터를 이용한 전달 방식

#include <iostream>

using namespace std;
void swap(int *x, int *y);

int main(void)
{
	int x=5, y=10;
	int *p_x,*p_y;
	p_x=&x;
	p_y=&y;
	cout << "Before swap, x " << x << " y " << y << endl;
	swap(p_x,p_y);
	cout << "After swap, x " << *p_x << " y " << *p_y << endl;
	return 0;
}
void swap(int *x, int *y)
{
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}