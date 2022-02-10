#include <iostream>

class A{
  int x;
  public:
    A(int c) : x(c){}
    int& access_x() {return x;} //x의 레퍼런스를 리턴
    int get_x() {return x;} //x의 값을 리턴
    void show_x() {std::cout << x << std::endl;}
};

int main(){
  A a(5);
  a.show_x();

  int& c = a.access_x(); //c가 다시 x의 별명이된다.
  c = 4; //즉 c를 건드리면 x를 건드리는 것과 마찬가지
  a.show_x(); //4

  int d = a.access_x(); //d의 형식이 int이기 때문에, d에 x의 값이 전달된다.
  d = 3; 
  a.show_x(); //즉 d는 x에 영향을 주지않는다.

  int f = a.get_x(); //f는 레퍼런스가 아닌 독립된 변수이기 때문에, 역시 x에 영향을 주지 않는다.
  f = 1;
  a.show_x(); //4
/*
  int& e = a.get_x(); 레퍼런스에 값을 대입하려고한다.
  이때, a.get_x()의 새로운 임시 객체 A가생성되는데, e에 A를 대입하는순간 A는 사라진다. A의 레퍼런스인 e는 A가 존재해야만 하는데, A가 사라지므로 오류가 발생하게된다.
  e=2;
  a.show_x();


*/





}