#include <string.h>
#include <iostream>

class Test {
  char c;

  public :
    Test(char _c) {
      c = _c;
      std::cout << "constructor called!" << c << std::endl;
    }
    ~Test() {std::cout << "destructor called"<<c << std::endl;}
};

void simple_function() {Test b('b');} //Test b는 simple_function()에 속해있는 객체이므로 이 지역이 파괴될때 소멸자가 실행된다.
int main(){
  Test a('a'); //Test a는 int main()에 속해있으므로 main이 시작될때 생성자호출
  simple_function();//생성자 호출 + simple_function()이 끝날때 소멸자 호출
  return 0;//main()함수가 끝날때 Test a의 소멸자가 호출
}