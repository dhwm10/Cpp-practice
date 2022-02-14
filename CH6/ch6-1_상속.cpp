#include <string>
#include <iostream>

class Base {
    std::string s;
    public:
        Base() : s("base!") { std::cout<<"base class"<<std::endl;}
        void what() { std::cout<< s << std::endl;}
};

class Derived : public Base {
    std::string s;
    
    public:
        Derived() : Base(), s("derive!") {
            std::cout << "derived class" <<std::endl;
            what(); //Base를 상속했고, 겉보기엔 같은 s라도 Base속의 what -> Base속의 s기 때문에,
            //base!가 실행된다. dreive!를 출력하고싶으면, Derived에 what함수를 만들면된다.
            //가장 가까운 what을 찾아가기 때문에 derived의 what이 실행된다
        }
        
};
int main() {
    std::cout << " === base class created ===" <<  std::endl;
    Base p;

    std::cout << " === derived class created ===" <<  std::endl;
    Derived c;

    return 0;
}