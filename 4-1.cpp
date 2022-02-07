#include <iostream>

class Animal {
    private : //멤버 변수 member variable
        //private의 경우 class 내에서의 접근만 가능하다.
        int food;
        int weight;
    public : //멤버 함수 member function
        //public의 경우 class 외부에서의 접근도 가능하다.
        void set_animal(int _food, int _weight){
            food = _food;
            weight = _weight;
        }
        void increase_food(int inc){
            food += inc;
            weight += inc / 3;
        }
        void view_stat(){
            std::cout << "this animal's food    :"<<food<<std::endl;
            std::cout << "this animal's weight  :"<<weight<<std::endl;
        }
    
};

int main(){
    Animal animal; //Animal 클래스의 새로운 객체 animal 선언
    animal.set_animal(100,50);
    animal.increase_food(30);

    animal.view_stat();




    return 0;
}