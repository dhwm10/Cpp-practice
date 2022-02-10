#include <iostream>

int main(){
    int i; //
    char c;
    double d;
    float f;
//변수명 정의

    int number_of_people; //1. 띄어쓰기 칸에 _
    int NumberOfPeaple; //2. 띄어쓰기 뒤에 대문자기호

//for, while 
    int sum = 0;
    for (int i=1; i<=10; i++){ // for문 내에서 i정의 가능
        sum += i;
    }
    i = 1;
    while (i<=10){ // while문 역시 기존의 C와 동일
        sum+=i;
        i++;
    }

//cin의 사용
    int user_input;
    std::cin >> user_input; // scanf대신 std에서 정의된 cin을 사용할 수 있다. 자료형을 알아서 해석

//switch의 사용
    switch (user_input) { //switch문 역시 기존의 C와 동일
        case 1:
            std::cout << "1" << std::endl;
        case 2:
            std::cout << "2" << std::endl;
        case 3:
            std::cout << "3" << std::endl;
        default:
            break;
    }




    return 0;
}