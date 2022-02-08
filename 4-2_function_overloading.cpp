#include <iostream>
//함수의 오버로딩
//함수의 이름이 같더라도 인자가 다르면 다른 함수로 인식한다
void print(int x){std::cout << "int : "<<x<<std::endl;};
void print(char x){std::cout<< "char : "<<x<<std::endl;};
//void print(double x){std::cout<< "double : "<<x<<std::endl;};

/*
컴파일러에서의 함수 오버로딩 과정

1단계
자신과 타입이 정확히 일치하는 함수를 찾는다.

2단계
정확히 일치하는 타입이 없는 경우 아래와 같은 형변환을 통해서 일치하는 함수를 찾아본다.
-Char, Unsigned Char, Short => int
-Unsigned Short는 크기에 따라 int 혹은 Unsigned Int로 변환
-Float => Double
-Enum => Int

3단계
위와 같이 변환해도 일치하는 것이 없다면 아래의 좀 더 포괄적인 형변환을 통해 일치하는 함수를 찾아본다.
-임의의 numeric 타입은 다른 숫자타입으로 변환된다. ex(float -> int)
-Enum도 임의읭 숫자 타입으로 변환된다. ex(enum -> double)
-0은 포인터 타입이나 숫자타입으로 변환된 0은 포인터 타입이나 숫자 타입으로 변환된다.
-pointer는 void pointer로 변환된다.

4단계
유저 정의된 타입변환으로 일치하는 것을 찾는다.
만약 컴파일러가 위과정을 통하더라도 일치하는 함수를찾을 수 없거나 같은 단계에서 두 개 이상
일치하는 경우에 모호하다라고 판단해서 오류를 발생하게 된다.

*/




int main(){
    int a = 1;
    char b = 'c';
    double c = 3.2f;

    print(a); // int를 인자로 받는 print
    print(b); // char를 인자로 받는 print
    // (error) print(c); // double은 없으므로

    /*
    1단계 : 없다.
    2단계 : double은 해당 x
    3단계 : 임의의 숫자타입 => double -> char or int 2개가 걸리므로 모호하다라고 판단.

    */
    return 0;
}