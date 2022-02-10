#include <iostream>

int change_val(int *p){ //pointer p를 인자로 받는다.
    *p = 3; //참조하여 값을 바꾸어준다.
    return 0;
}

int change_val_by_reference(int & p){ //참조자 p를 통해 pointer로 직접 가르키는 것이 아닌, 참조자의 값을 변경하여 원래의 변수의 값을 조작한다.
    p = 3;
    return 0;
}

int& function(int& a){
    a=5;
    return a;
}
/*
    int main(){
        int b = 2;
        int c = funciton(b);  function(b) 는 살아있는 지역변수 b를 계속 참조하기 때문에 가능하다.


        return 0;
    }

*/
int func(){
    int a=3;
    return a;
}


int main(){
    int number = 5;

    std::cout<<number<<std::endl; //5
    change_val(&number); // number = 3
    std::cout<<number<<std::endl; // 3


//참조자의 사용
    int a = 3;
    int& anotehr_a = a; // 자료형 + &을 통해 참조자를 정의할 수 있다. 
    //이때 another_a는 다른 변수의 참조자가 될 수 없음에 주의하자. 반면

    int* x = &a;
    int b = 1;
    x = &b; //포인터는 원래 값을 버리고 새로운 값을 받을 수 있다.


    anotehr_a = 5; // another_a는 a의 참조자이기 때문에 another_a에 하는 작업은 a에 하는 작업에 적용된다.
    std::cout << a << std::endl;
    std::cout << anotehr_a << std::endl;
    a = 4; // 같은 논리로 a에 작업하는 것은 another_a에 작업하는 것에도 적용
    std::cout << a << std::endl;
    std::cout << anotehr_a << std::endl;

    change_val_by_reference(a); // int & p = a;
//참조자의 이용
    int q;
    int & w = q;
    int & e = w; //여러 참조자를 겹쳐서 정의할 수 있다.


//상수 참조자의 이용
    //int &ref = 4; // error
    const int &ref = 4; //const로 참조자를 지정하는 것은 가능
    int p = ref;

//배열의 레퍼런스의 이용

    //일반적으로 레퍼런스의 배열은 불가능하다 가령
    //int& ref arr[2] = {a,b}; 와 같은 코드는 불가능
    int arr[3] = {1,2,3};
    int(&reff)[3] = arr; //다음과 같은 배열의 레퍼런스는 가능하다
    
    reff[0] = 1;
    reff[1] = 3;
    reff[2] = 2;

//리턴값을 참조의 이용
    //int& r = func(); error, 
    const int& r = func(); //예외적으로 const로 받을 경우, 함수의 리턴값의 생명이 연장된다.
    
//cin의 사용
    int cin_num;
    std::cin >> cin_num;



}