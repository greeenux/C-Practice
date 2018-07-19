/*
참조자에 주소 연산자 "&"를 사용하여 보자.
참조자의 주소를 물어보면 가리키고 있는 주소가 반환된다. 이것이 참조자의 본질이다. 가리키고 있는 것에 대한 또 다른 이름이기 때문이다.
*/

//참조자의 주소를 알아보자

#include <iostream>

int main(void)
{
	using namespace std;
	int Green;
	int &r_RefGreen=Green;

	Green= 7;
	cout << "Green :" << Green <<endl;
	cout << "r_RefGreen :" <<r_RefGreen <<endl;

	cout << "address of Green : " << &Green << endl;
	cout << "address of r_RefGreen : "<< &r_RefGreen <<endl;
	return 0;
}
/*
참조자는 만들어질 때 초기화되고 그 타겟에 대한 동의어로 여겨지는데 주소 연산자를 쓸 대에도 마찬가지이다.
클래스 객체에서도 적용 될 수 있다.
SimpleCat 이라는 클래스가 있고 객체엔 Green이 있다고 가정하자.
SimpleCat Green;
SimpleCat &r_Green=Green;

SimpleCat 변수는 하나이다. 그러나 두 개의 식별자가 클래스의 같은 객체에 접근한다.
하나의 식별자가 가하는 영향은 객체에 반영되고 다른 식별자 역시 반영되게 된다.
참조자를 쓸 때에는 주소 연산자를 쓰지 않는다. 단지 타겟 변수를 쓰듯이(그대로의 이름) 참조자를 쓴다.
*/