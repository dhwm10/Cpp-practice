#include <iostream>

class const_test{
  const int test_val; //const 형식의 test_val지정
  public :
    const_test(int default_val);//생성자
};

const_test::const_test(int default_val) : test_val(default_val){};

int main(){
  const_test object1(5); //const int test_val에 default_val(5)가 들어갔으므로, const_test의 test_val은 변경할 수 없다.

  return 0;

}