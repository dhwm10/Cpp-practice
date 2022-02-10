#include <iostream>

class Marine {
  int hp;                // 마린 체력
  int coord_x, coord_y;  // 마린 위치
  int damage;            // 공격력
  bool is_dead;

 public:
  Marine();              // 기본 생성자
  Marine(int x, int y);  // x, y 좌표에 마린 생성

  int attack();                       // 데미지를 리턴한다.
  void be_attacked(int damage_earn);  // 입는 데미지
  void move(int x, int y);            // 새로운 위치

  void show_status();  // 상태를 보여준다.
};

Marine::Marine() : hp(50), coord_x(0), coord_y(0), damage(5), is_dead(false) {}
/*
(생성자 이름) : var1(arg1), var2(arg2) {}
=> 초기화 리스트 (initializer list)라고 불리며, 기존에 했던 생성자와 같은 역할을 해준다
ex) hp = 50 / hp(50)

한 가지 흥미로운 점은 var1과 arg1의 이름이 같아도 된다. 예를들어
Marine(int a) : a(a){}이런식

<초기화 리스트를 사용하는 이유>
초기화 리스트는 "생성과 초기화를 동시에" 하게 해준다.

반면 예전 버전의 생성자는 생성을 한 후에, 대입을 수행하므로 하는일이 더 많아진다.즉, 디폴트 생성자를 호출한 후에 대입이 수행되므로 비효율적이다.

*/

Marine::Marine(int x, int y)
    : coord_x(x), coord_y(y), hp(50), damage(5), is_dead(false) {}

void Marine::move(int x, int y) {
  coord_x = x;
  coord_y = y;
}
int Marine::attack() { return damage; }
void Marine::be_attacked(int damage_earn) {
  hp -= damage_earn;
  if (hp <= 0) is_dead = true;
}
void Marine::show_status() {
  std::cout << " *** Marine *** " << std::endl;
  std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) "
            << std::endl;
  std::cout << " HP : " << hp << std::endl;
}

int main() {
  Marine marine1(2, 3);
  Marine marine2(3, 5);

  marine1.show_status();
  marine2.show_status();
}
