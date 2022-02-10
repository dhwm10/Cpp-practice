#include <iostream>

class const_func {
  int a;
  public :
    const_func(int a_);
    void test() {
      std::cout<<a<<std::endl;
    }
    //void const_() const;
};
/*
void const_func::const_() const{
  a = 4;
};
*/
int main(){
  std::cout<<">??"<<std::endl;
  const_func test1(2);
  //test1.const_();
  test1.test();
  return 0;
}