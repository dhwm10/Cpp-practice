#include <string.h>
#include <iostream>

class Marine {
  int hp;
  int coord_x, coord_y;
  int damage;
  bool is_dead;
  char* name;


  public :
    Marine();
    Marine(int x, int y, const char* marine_name);
    ~Marine();
    int attack();
    void be_attacked(int damage_earn);
    void move(int x, int y);


    void show_status();
};
Marine::Marine(int x, int y, const char* marine_name){
  name = new char[strlen(marine_name)+1];
  strcpy(name, marine_name);

  coord_x = x;
  coord_y = y;
  hp = 50;
  damage = 5;
  is_dead = false;
}

void Marine::move(int x, int y) {
  coord_x = x;
  coord_y = y;
}
int Marine::attack() {return damage;}
void Marine::be_attacked(int damage_earn) {
  hp -= damage_earn;
  if (hp<=0) is_dead = true;
}
void Marine::show_status() {
  std::cout << " *** Marine : "<< name << " ***" <<std::endl;
  std::cout << " Location : ( "<< coord_x << " , " << coord_y << " ) " << std::endl;
  std::cout << " HP : "<< hp << std::endl;
}
Marine::~Marine() { // 소멸자의 경우 클래스명 앞에 ~을 붙여 구분한다. 이때 소멸자는 인자를 받지 않으며 이는 소멸자 함수는 오버로딩 되지않는다.
  std::cout << name << "'s destructor call ! "<<std::endl;
  if (name != NULL) {
    delete[] name; //소멸자에서 동적할당했던 데이터를 delete해준다
  }
}

int main() {
  Marine* marines[100];

  marines[0] = new Marine(2, 3, "Marine 2");
  marines[1] = new Marine(1, 5, "Marine 1");

  marines[0]->show_status();
  marines[1]->show_status();

  std::cout << std::endl << "marine1 attacks marine2!"<<std::endl;

  marines[0]->be_attacked(marines[1]->attack());

  marines[0]->show_status();
  marines[1]->show_status();

  delete marines[0];
  delete marines[1];
  return 0;
}