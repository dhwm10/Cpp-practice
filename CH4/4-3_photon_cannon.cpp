#include <string.h>
#include <iostream>

class Photon_Cannon {
  int hp, shield;
  int coord_x, coord_y;
  int damage;

  public :
    Photon_Cannon(int x, int y);
    Photon_Cannon(const Photon_Cannon& pc);//복사 생성자의 표준 정의, 반드시 const를 붙여주자

    void show_status();
};
Photon_Cannon::Photon_Cannon(const Photon_Cannon& pc) { //참조자로 정의하는 이유는 함수의 인자를 받고싶으면 원래는 pointer로 직접 주소를 지정해주어야하지만 참조자를 통해 그 과정을 생략할 수 있다.
/*

다른표현으로는
const Photon_Cannon* pc (pointer로 직접받은 후)
hp = (*pc).hp; (*을통해 불러오고, .을통해 hp정보 획득)
shield = pc -> shield (윗과정을 간단하게)

*/
  std::cout << "copy constructor called !" << std::endl;
  hp = pc.hp; //const이므로 pc.hp자체를 바꿀 순 없지만 hp에 대입은 가능하다.
  shield = pc.shield;
  coord_x = pc.coord_x;
  coord_y = pc.coord_y;
  damage = pc.damage;
}
Photon_Cannon::Photon_Cannon(int x, int y) {
  std::cout << "Constructor called !" << std::endl;
  hp = shield = 100;
  coord_x = x;
  coord_y = y;
  damage = 20;
}
void Photon_Cannon::show_status() {
  std::cout << "Photon Cannon " << std::endl;
  std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) "
            << std::endl;
  std::cout << " HP : " << hp << std::endl;
}
int main() {
  Photon_Cannon pc1(3, 3);
  Photon_Cannon pc2(pc1);
  Photon_Cannon pc3 = pc2; //복사 생성자 호출 , 복사생성자 역시 생성자의 일종이기 때문에 생성될 때 실행된다는 것을 잊지말자

  pc1.show_status();
  pc2.show_status();
}