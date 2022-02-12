class A {
 private:

    void func_a(){
        B b_;
        //b_.b; => B는 아직 A를 친구로 생각하지 않는다
    }

  void private_func() {}
  int private_num;

  /*
   B 는 A 의 친구! friend + (친구를 맺을 대상)
  친구를 맺게 되면 private한 공간도 들어갈 수 있게된다.
  */
  friend class B;
/*
A는 B를 친구로 생각하기 때문에 A의 private한공간을 열람할 수 있게
허락하지만, B는 아직 A를 친구로 생각하지 않기 떄문에
A가 B에 접근하려하면 오류를 발생시킨다.
*/



  // func 은 A 의 친구!
  friend void func();
};

class B {
 private :
    int b;
 public:
  void b() {
    A a;

    // 비록 private 함수의 필드들이지만 친구이기 때문에 접근 가능하다.
    a.private_func();
    a.private_num = 2;
  }
};

void func() {
  A a;

  // 비록 private 함수의 필드들이지만 위와 마찬가지로 친구이기 때문에 접근
  // 가능하다.
  a.private_func();
  a.private_num = 2;
}

int main() {}