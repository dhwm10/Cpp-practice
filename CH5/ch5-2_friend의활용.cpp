#include <iostream>
class A {
    

    private:
        int num_A;
    public :
        friend void frined_need(const A& a, const A& b);
        A(int num_A) : num_A(num_A) {}
};



/*
외부의함수에서 클래스 A의 레퍼런스의 private한 변수에 접근하도록
허용하려면, friend를 맺으면 된다.
*/
void frined_need(const A& a, const A& b){
    std::cout << a.num_A + b.num_A << std::endl;
}
