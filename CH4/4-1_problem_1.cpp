#include <iostream>

class Date {
    int year_;
    int month_;
    int day_;

    int is_month_31[12] = {1,0,1,0,1,0,1,1,0,1,0,1};

    public:
        void SetDate(int year, int month, int date){
            year_ = year;
            month_ = month;
            day_ = date;
        };
        void AddDay(int inc){
            if (is_month_31[month_-1]){
                if (day_ + inc <= 31){
                    day_ += inc;
                }
                else{
                    day_ = day_ + inc - 31;
                    month_ ++;
                }
            }
            else{
                if (month_ == 2){
                    if (day_ + inc <= 28){
                        day_ += inc;
                    }
                    else{
                        day_ = day_ + inc - 28;
                        month_ ++;
                    }
                }
                else if (day_ + inc <= 30){
                    day_ += inc;
                }
                else{
                    day_ = day_ + inc - 30;
                    month_ ++;
                }
            }
        };
        void AddMonth(int inc){
            month_ += month_ + inc < 13 ? inc : inc - 12, year_++;
        };
        void Addyear(int inc){
            year_ += inc;
        };
        void ShowDate(){
            std::cout << "year : " << year_ << std::endl;
            std::cout <<"month : " << month_ << std::endl;
            std::cout << "day   :" << day_ <<std::endl;
        }
};

int main(){

    Date mydate;
    mydate.SetDate(2002,2,27);
    mydate.AddDay(3); //2월 예외처리
    mydate.ShowDate();
    mydate.AddMonth(13); // 년도 넘어가는 예외처리
    mydate.ShowDate();
    mydate.AddDay(28); // 30일 확인
    mydate.ShowDate();
    mydate.AddDay(4); //30일에서 AddDay 확인
    mydate.ShowDate();
    return 0;
}