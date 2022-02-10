#include <iostream>

class Marine {
  static int total_marine_num;
  const static int i = 0;

  int hp;                // 마린 체력
  int coord_x, coord_y;  // 마린 위치
  bool is_dead;

  const int default_damage;  // 기본 공격력

 public:
  Marine();              // 기본 생성자
  Marine(int x, int y);  // x, y 좌표에 마린 생성
  Marine(int x, int y, int default_damage);

  int attack();                          // 데미지를 리턴한다.
  Marine& be_attacked(int damage_earn);  // 입는 데미지
  void move(int x, int y);               // 새로운 위치

  void show_status();  // 상태를 보여준다.
  static void show_total_marine();
  ~Marine() { total_marine_num--; }
};
int Marine::total_marine_num = 0;
void Marine::show_total_marine() {
  std::cout << "전체 마린 수 : " << total_marine_num << std::endl;
}
Marine::Marine()
    : hp(50), coord_x(0), coord_y(0), default_damage(5), is_dead(false) {
  total_marine_num++;
}

Marine::Marine(int x, int y)
    : coord_x(x),
      coord_y(y),
      hp(50),

      default_damage(5),
      is_dead(false) {
  total_marine_num++;
}

Marine::Marine(int x, int y, int default_damage)
    : coord_x(x),
      coord_y(y),
      hp(50),
      default_damage(default_damage),
      is_dead(false) {
  total_marine_num++;
}

void Marine::move(int x, int y) {
  coord_x = x;
  coord_y = y;
}
int Marine::attack() { return default_damage; }
Marine& Marine::be_attacked(int damage_earn) {
  hp -= damage_earn;
  if (hp <= 0) is_dead = true;

  return *this; //this는 이 함수 (be_attacked)를 호출한 객체를 가리키는 포인터(주소)이다. 여기에 *을 붙임으로써 객체를 리턴하는데 반환 형식이 레퍼런스이므로 리턴값을 곧 객체로 사용해도 무방(.(함수명))을 사용해도 주소상 문제가 없다는 뜻임.
}
void Marine::show_status() {
  std::cout << " *** Marine *** " << std::endl;
  std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) "
            << std::endl;
  std::cout << " HP : " << hp << std::endl;
  std::cout << " 현재 총 마린 수 : " << total_marine_num << std::endl;
}

int main() {
  Marine marine1(2, 3, 5);
  marine1.show_status();

  Marine marine2(3, 5, 10);
  marine2.show_status();


  marine2.be_attacked(marine1.attack()).be_attacked(marine1.attack());
  //marine2.be_attacked(marine1.attack())이 marine2의 레퍼런스(자신)을 반환하기때문에 다시 .으로 함수를 호출 할 수 있다. 하지만 함수의 반환이 레퍼런스가 아닌 그저 class였다면, 값을 전달할때, 임시객체가 반환되기때문에, 우리가 원하는 객체가 아닌 임시객체의 함수를 호출하려하기때문에 원하지 않는 결과가 발생한다.

  std::cout << std::endl << "마린 1 이 마린 2 를 두 번 공격! " << std::endl;
  marine2.be_attacked(marine1.attack()).be_attacked(marine1.attack());

  marine1.show_status();
  marine2.show_status();
}