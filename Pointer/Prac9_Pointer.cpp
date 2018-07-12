/*
실종된 포인터란 포인터에 대해 delete를 사용하여 이 포인터가 가리키는 메모리를 해제한 뒤, 나중에 그 포인터에 주소를 할당하지 않은 체 그 포인터를 사용할 때 일어난다.
delete로 방출된 포인터를 사용하지 말자. 이 포인터는 그 전의 메모리 주소를 갖고 있지만 컴파일러는 그 메모리를 해제하였다.
이 메모리에 주소를 쓰면 프로그램이 깨질 수 있고, 더 안 좋은 경우는 프로그램이 아무런 오류가 발겸되이 없이 잘 돌다가 다른 곳에서 죽는 경우도 있다.
안전하게 포인터를 삭제한 후, 포인터를 널(0)로 지정한다.
이런 실종된 포인터를 댕글링(dnagling)포인터, stray포인터라 한다.
*/

typedef unsigned short int USHORT;
#include <iostream>

int main(void)
{
	USHORT *pInt = new USHORT;
	*pInt = 10;
	std:: cout << "*pInt: " << *pInt << std::endl;
	delete pInt;
	*pInt=20;
	int *pGreen = new int(50000);
	std::cout << "*pInt: " << *pInt <<std::endl;
	std::cout << "pGreen: " << *pGreen << std::endl;
	delete pGreen;
	return 0;
}
//10 이란 결과를 저장하여 놓고 해재를 한 후 20을 넣었다. 그 자리에는 20이 할당되어 잇을 것이다.
//그런데 새롭게 pGreen이라는 포인터를 힙에 생성하였으므로 그 자리를 그대로 사용할 것이고(아닐 수도 있지만), 50000이라는 값이 새롭게 자리에 들어간다.
//따라서 20이라고 할당한 값은 존재하지 않게 된다. 이러한 것은 아무런 오류없이 돌아가지만, 찾아내기 힘들 수 있다. 유의하도록 하자!
