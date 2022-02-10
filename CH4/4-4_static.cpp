#include <iostream>

class Marine {
  static int total_marine_num;

  int hp;                // 마린 체력
  int coord_x, coord_y;  // 마린 위치
  bool is_dead;

  const int default_damage;  // 기본 공격력

  public:
  Marine();              // 기본 생성자
  Marine(int x, int y);  // x, y 좌표에 마린 생성
  Marine(int x, int y, int default_damage);

  int attack();                       // 데미지를 리턴한다.
  void be_attacked(int damage_earn);  // 입는 데미지
  void move(int x, int y);            // 새로운 위치

  void show_status();  // 상태를 보여준다.
  static void show_marine_num(); //static형식으로 함수를 정의하면 class객체를 만들지 않아도 함수를 호출할 수 있다.

  //쉽게 설명하면 어떠한 객체도 static함수를 '소유'하고 있지 않다는 뜻이다.

  ~Marine() { total_marine_num--; }
};
int Marine::total_marine_num = 0;

void Marine::show_marine_num() {
  std::cout<<"total marine num : "<<total_marine_num<<std::endl; //total marine num은 static변수이기 때문에 객체없이도 호출가능
}

Marine::Marine()
    : hp(50), coord_x(0), coord_y(0), default_damage(5), is_dead(false) {
  total_marine_num++;
}

Marine::Marine(int x, int y)
    : coord_x(x), coord_y(y), hp(50), default_damage(5), is_dead(false) {
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
void Marine::be_attacked(int damage_earn) {
  hp -= damage_earn;
  if (hp <= 0) is_dead = true;
}
void Marine::show_status() {
  std::cout << " *** Marine *** " << std::endl;
  std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) "
            << std::endl;
  std::cout << " HP : " << hp << std::endl;
  std::cout << " 현재 총 마린 수 : " << total_marine_num << std::endl;
}

void create_marine() {
  Marine marine3(10, 10, 4); //marine3생성 + static 변수인 total_marine_num ++
  marine3.show_status();
  //marine3소멸 + 소멸자의 호출과 동시에 total_marine_num--
}
int main() {
  Marine::show_marine_num(); //Marine객체를 만들지 않아도 호출이 가능한 static function
  Marine marine1(2, 3, 5); //marine1은 main의 객체이기 때문에, main이 끝나기 직전까지 유지된다.
  marine1.show_status();
  
  Marine marine2(3, 5, 10);
  marine2.show_status();

  create_marine(); //그러나 create_marine의 객체인 marine3은 create_marine이 끝나는 직전에 소멸된다.

  std::cout << std::endl << "마린 1 이 마린 2 를 공격! " << std::endl;
  marine2.be_attacked(marine1.attack());

  marine1.show_status();
  marine2.show_status();
}