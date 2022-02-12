#include <iostream>

class plus {
    int x;
    int y;

    int res;

    public :
        plus(int x, int y, int res);
        int plus_val();
};
plus::plus(int x, int y, int res) : x(x),y(y),res(res) {}

int plus::plus_val() {

    std::cout<<"overloading success"<<std::endl;
    res = x + y;
    return res;
}

int operator+(plus& p){
    return p.plus_val();
}

int main(){
    plus pp(1,3,0);
    std::cout << +(pp);
    return 0;
}