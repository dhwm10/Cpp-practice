#include <iostream>


class test{
    int a;
    int b;
    int c;

    public :
        void set_value(int a_, int b_, int c_); //선언만 한뒤에
        void plus_value(int inc);
        void show_value();
};

//내용은 클래스 밖에서 관리할 수 있다.
void test::set_value(int a_, int b_, int c_){
    a = a_;
    b = b_;
    c = c_;
}// 관리를원하는클래스 :: 멤버함수명

void test::plus_value(int inc){
    a += inc;
    b += inc;
    c += inc;
}

void test::show_value(){
    std::cout<<"a :"<<a<<std::endl;
    std::cout<<"b :"<<b<<std::endl;
    std::cout<<"c :"<<c<<std::endl;
}

int main(){

    test test_class;
    test_class.set_value(1,2,3);
    test_class.plus_value(4);
    test_class.show_value();
    return 0;
}