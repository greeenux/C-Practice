/*
참조자는 다시 값을 할당할 수 없다. 꼭 기억해야 한다.
다른 값을 대입을 하는 경우 나타나는 현상은, 새로운 값을 타겟에 대입하는 것처럼 보인다.
*/

//참조자에 대입하기(참조자 재설정 오류)

#include <iostream>

int main(void)
{
	using namespace std;
	int Green;
	int &r_Green= Green;
	Green=7;
	cout << "Green : " << Green <<endl;
	cout << "r_Green : " << r_Green << endl;

	cout << "&Green : " << &Green <<endl;
	cout << "&r_Green : " << &r_Green << endl;

	int Red=10;
	r_Green =Red;
	cout << "Green : " <<Green<<endl;
	cout << "r_Green : " <<r_Green << endl;
	cout << "Red :" << Red << endl;

	cout << "Address of Green : " << &Green <<endl;
	cout << "Address of r_Green : " << &r_Green << endl;
	cout << "Address of Red " << &Red << endl;

	return 0;
}
/*
살펴보면 값들이 전부 10으로 변하였다.
하지만 여전히 참조자(r_Green)는 Green을 가리키고 있으며, Red의 값만을 활용하고 주소는 변하지 않았다.
참조자는 처음 초기화할 때 한번 하는것을 제외하고는 변하지 않는다는것을 알아두자
*/