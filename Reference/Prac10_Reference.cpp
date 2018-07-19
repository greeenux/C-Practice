/*
매번 함수에 객체를 값으로 전달할 때마다 그 객체에 대한 복사가 일어난다. 또, 매번 함수로부터 객체를 값으로 하여 반환할 때마다 복사가 일어난다.
이 객체들은 스택에 복사됨을 알고 있다. 이렇게 하면 시간과 메모리가 소요된다.
내장 된 정수형 같은 객체를 쓸 때 이러한 과정은 별 일이 아닐 수 있다.
그러나 큰 객체의 경우는 대가가 크다. 사용자가 스택 위에 만든 객체는 각 멤버 변수들의 총합이다.
이 객체들 또한 사용자가 정의한 것일 수 있고, 이 큰 구조물을 스택에 복사하는 일은 성능과 메모리 사용에 큰 대가를 지불할 수 있다.
클래스와 함께 컴파일러가 특정 생성자를 호출할 때마다 각각에 대한 임시 복사(복사 생성자)가 만들어진다.
복사생성자는 객체가 복사할 때마다 호출되는 것인데 이정도만 알아두자.
지금 당장은 객체의 특정 생성자가 이 스택에 저장될 때마다 복사 생성자가 호출된다는 것만 아는 것으로 충분하다.
임시 객체가 없어지면 객체의 소멸자가 호출되고 함수가 반환될 때 호출된다.
객체가 함수에서 값으로 반환되면 역시 그 객체에 대한 복사본이 만들어지고 소멸된다.
큰 프로그램에서 이 생성자와 소멸자의 호출은 속도와 메모리 사용에 있어 크나큰 부담일 수 있다.
다음 예제를 통해 얼마나 자주 생성자와 소멸자가 호출되는지 보여줄 수 있다.
*/
//참조자에 의한 객체전달, 객체에 포이터 전달하기

#include <iostream>

using namespace std;

class SimpleCat
{
public:
	SimpleCat();
	SimpleCat(SimpleCat &); //생성자 복사한다.
	~SimpleCat();
};

SimpleCat::SimpleCat()
{
	cout << "Simple Cat Constructor...\n";
}

SimpleCat::SimpleCat(SimpleCat&)//복사 생성자
{
	cout << "Simple Cat Copy Construcotr\n";
}

SimpleCat::~SimpleCat()
{
	cout << "Simple Cat Desturctor\n";
}

SimpleCat FunctionOne (SimpleCat Green);
SimpleCat& FunctionTwo (SimpleCat &Green);//SimpleCat* FunctionTwo(SimpleCat *Green) 도 참조자 방식으라고 한다. 왜?
//왜냐하면 참조자 자체를 그때는 넣어주는 역할을 한것이다. 가 아니고 포인터 방식임... 내생각은.. 매개변수로 주는 값이 참조자라고 하여도, 그냥 주소로 줬다는 표현이 더 바른것 같음...

int main(void)
{
	cout << "mkaing a cat...\n";
	SimpleCat Green;
	cout << "Calling FunctionOne....\n";
	FunctionOne(Green);
	//FunctionOne으로부터 반환값은 어떤 객체에도 저장되지 않고, 따라서 임시로 만들어졌던 반환값은 소멸자를 호출하면서 버려진다.
	//FuncgionOne이 끝났기 때문에 지역 복사본이 범위를 벗어나고 소멸되며 소멸자를 호출하게 된다.
	cout << "Calling FunctionTwo...\n";
	FunctionTwo(Green);
	//FunctionTwo에서는 참조자 전달 방식으로 전달되었다. 따라서 아무런 복사본도 일어나지 않았고 따라서 출력도 되지 않는다.
	//다시 참조자를 반환하였는데 따라서 생성자나 소멸자가 호출되지 않았다.
	return 0;
	//마지막으로 프로그램이 끝나는데 main에서 사용된 클래스 객체 Green은 범위를 벗어나게 되며 마지막으로 소멸자가 호출된다.
}

//값 전달 방식의 FunctionOne
//객체를 값 전달 방식으로 호출하였기 때문에, SimpleCat의 객체가 호출된 함수에서 지역변수로 되어 스택에 저장되엇다.
//이때 복사 생성자가 호출된다.
SimpleCat FunctionOne(SimpleCat Green)
{
	cout << "Function One. Returning...\n";
	return Green;//이 객체가 main의 값으로 반환되어야 한다. 따라서 이는 또 다른 객체의 복사본을 만들고 복사 생성자를 호출한다.
}

//참조자 전달 방식의 FunctionTwo
SimpleCat& FunctionTwo(SimpleCat &Green)
{
	cout << "Function Two. returning ...\n";
	return Green;
}