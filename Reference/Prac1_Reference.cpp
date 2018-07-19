/*
참조자란 무엇인가?
참조란 일종의 다른 이름(별칭)이다. 참조자를 만들면 다른 객체의 이름으로(타겟) 초기화한다.
그때부터 참조자는 타겟에 대한 다른 이름으로 행세하고 참조자에게 가한 변화가 타겟에도 가해진다.

타겟의 형을 쓰고 참조 연산자(&) 다음에 참조자의 이름을 씀으로써 참조자를 만든다.

참조자는 변수 이름으로 쓸 수 있는 것은 모두 다 되는데, 여기서는 r_이라는 단어를 접두사로 용하겠다.
Green이라는 변수명을 갖는다면 그 변수에 대한 참조자를 다음과 같이 만들 수 있다.

int &r_Reference= Green;

이는 r_Reference는 green을 참조하도록 초기화된 정수형 참조자이다 라고 읽는다.

참조연산자는 주소연산자와 같은 기호이지만 같은 연삱는 아니다. 하지만 상당히 관련되어 있다.
*/

//참조자 사용 예

#include <iostream>

int main(void)
{
	using namespace std;

	int Green;
	int &r_RefGreen=Green;
	//r_RefGreen = Green;

	Green=7;
	cout << "Green : " << Green << endl;
	cout << "r_RefGreen : " << r_RefGreen << endl;

	r_RefGreen =10;
	cout << "Green : " << Green << endl;
	cout << "r_RefGreen : " << r_RefGreen << endl;

	return 0;
}
//하나 주의해야 할 사항은 참조자를 선언한 후, 초기화를 해주지 않으면, 컴파일러에서 오류를 일으킨다. 실제로 실험해 보길 바란다.