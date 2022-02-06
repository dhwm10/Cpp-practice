#include <iostream>

typedef struct Animal {
    char name[30];
    int age;
    int health;
    int food;
    int clean;
}Animal; //Animal Animal 선언

void create_animal(Animal *animal){ //T *p, animal이란 Animal 타입의 포인터를 받는다.
    std::cout << "animal name? ";
    std::cin >> animal -> name; //(*animal).name == animal->name

    std::cout << "animal age? ";
    std::cin >> animal -> age;

    animal -> health = 100;
    animal -> food = 100;
    animal -> clean = 100;
}

void play(Animal *animal) {
  animal->health += 10;
  animal->food -= 20;
  animal->clean -= 30;
}

void one_day_pass(Animal *animal) {
 
  animal->health -= 10;
  animal->food -= 30;
  animal->clean -= 20;
}
void show_stat(Animal *animal) {
  std::cout << animal->name << "의 상태" << std::endl;
  std::cout << "health : " << animal->health << std::endl;
  std::cout << "food : " << animal->food << std::endl;
  std::cout << "clean : " << animal->clean << std::endl;
}

//C의 구조체를 학습한 후에 다시 공부해 볼 것.

int main() {
  Animal *list[10]; //구조체 포인터 배열 선언? -> 공부필요
  int animal_num = 0;

  for (;;) { //
    std::cout << "1. 동물 추가하기" << std::endl;
    std::cout << "2. 놀기 " << std::endl;
    std::cout << "3. 상태 보기 " << std::endl;

    int input;
    std::cin >> input;

    switch (input) {
      int play_with;
      case 1:
        list[animal_num] = new Animal; //list -> struct pointer array, new Animal = ??
        create_animal(list[animal_num]); //create_animal은 Animal *animal을 받는다 -> pointer(list[animal_num])를 받으니 맞음.

        animal_num++;
        break;
      case 2:
        std::cout << "누구랑 놀게? : ";
        std::cin >> play_with;

        if (play_with < animal_num) play(list[play_with]);

        break;

      case 3:
        std::cout << "누구껄 보게? : ";
        std::cin >> play_with;
        if (play_with < animal_num) show_stat(list[play_with]);
        break;
    }

    for (int i = 0; i != animal_num; i++) {
      one_day_pass(list[i]);
    }
  }
  for (int i = 0; i != animal_num; i++) {
    delete list[i];
  }
}