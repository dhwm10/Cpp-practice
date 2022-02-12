#include <iostream>
#include <string.h>
class Explicit_Class {
    int a;
    public :
        explicit Explicit_Class(int a_);
//explicit을 붙여주었으므로 암시적으로 변환 되는 것을 막는다.
        Explicit_Class(const char* a_);

        void show_status();
};

Explicit_Class::Explicit_Class(int a_){
    a = a_;
}

Explicit_Class::Explicit_Class(const char* a_){
    a = strlen(a_);
}


void Explicit_Class::show_status(){
    std::cout << "a : " << a << std::endl;
}

void DoSomethingWithInt(Explicit_Class e){
    std::cout << "the function is called" << std::endl;
}


int main(){
    // DoSomethingWithInt(3); 
/* DoSomethingWithInt 는 3을 인자로 받는 것이 아닌,
Explicit_Class를 인자로 받는다. 그러나 Explicit_Class의 생성자
중에, int a_를 받는 생성자가 있으므로 컴파일러는 알아서 생성자를
호출한다. 이렇듯 알아서 바꾸어 주는 것을 암시적 변환이라고 하며
implicit conversion이라고 부른다. 이것을 원하지 않는 경우 함수를
정의하는 과정에서 앞에 explicit을 붙여주면 해결된다.
*/
    return 0;
}