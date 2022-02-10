#include <iostream>

class Date{
    int year_;
    int month_;
    int day_;

    public:
    Date(){ //constructor
        std::cout << "basic constructor call"<<std::endl;
        year_ = 2022;
        month_ = 2;
        day_ = 8;
    }
    Date(int year, int month, int day){ //constructor
        year_ = year;
        month_ = month;
        day_ = day;
    }
    void show_date();
};

void Date::show_date(){
    std::cout<<"year : "<<year_<<std::endl;
    std::cout<<"month : "<<month_<<std::endl;
    std::cout<<"day : "<<day_<<std::endl;
}

int main(){
    Date date =Date(); // 기본 생성자 호출 (인자가 없는)
    Date date2 = Date(2002,6,25); // 생성자 호출 (인자가 있는)

    date.show_date();
    date2.show_date();
    return 0;
}