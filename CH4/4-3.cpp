#include <iostream>

class Marine {
    int hp;
    int coord_x, coord_y;
    int damage;
    bool is_dead;

    public:
        Marine();
        Marine(int x, int y);

        int attack();
        void be_attacked(int damage_earn);
        void move(int x, int y);

        void show_status();
};

Marine::Marine() { //기본 생성자
    hp = 50;
    coord_x = coord_y = 0;
    damage = 5;
    is_dead = false;
}
Marine::Marine(int x, int y){
    coord_x = x;
    coord_y = y;
    hp = 50;
    damage = 5;
    is_dead = false;
}
void Marine::move(int x, int y){
    coord_x = x;
    coord_y = y;
}
int Marine::attack() { return damage;}
void Marine::be_attacked(int damage_earn) {
    hp -= damage_earn;
    if(hp<=0) {is_dead = true;}
}
void Marine::show_status() {
    std::cout << "***Marine***"<<std::endl;
    std::cout<<"Location : ( "<<coord_x<<" , "<<coord_y<<")"
    <<std::endl;
    std::cout<<" HP : "<< hp << std::endl;
}

int main(){

    /* 직접 하나하나 객체를 만드는법
    Marine marine1(2,3);
    Marine marine2(3,5);

    marine1.show_status();
    marine2.show_status();

    std::cout << std::endl << "marine1 attacks marine2!" << std::endl;
    marine2.be_attacked(marine1.attack());

    marine1.show_status();
    marine2.show_status();
    */
   Marine* marines[100]; //Marine 클래스의 포인터 배열을 생성
   marines[0] = new Marine(2, 3); //0번째 주소에 Marine
   marines[1] = new Marine(3, 5);







}











