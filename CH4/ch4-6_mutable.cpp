#include <iostream>

class A {
  mutable int data_;

 public:
  A(int data) : data_(data) {}
  void DoSomething(int x) const {
    data_ = x;  // 불가능!
  }

  void PrintData() const { std::cout << "data: " << data_ << std::endl; }
};
/*
const function은 원래 private변수 (member 변수) 를 변경할 수
없다. 그러나 mutable 변수로 지정된 것은 예외적으로 변경할 수
있다.
*/
int main() {
  A a(10);
  a.DoSomething(3);
  a.PrintData();
}