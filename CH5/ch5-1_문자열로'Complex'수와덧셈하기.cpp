#include <iostream>
#include <cstring>

class Complex {
 private:
  double real, img;

  double get_number(const char* str, int from, int to) const;

 public:
  Complex(double real, double img) : real(real), img(img) {}
  Complex(const Complex& c) { real = c.real, img = c.img; }
  Complex(const char* str);
  Complex operator+(const Complex& c) const;
  Complex operator+(const char* str) const;

  Complex operator-(const Complex& c) const;
  Complex operator*(const Complex& c) const;
  Complex operator/(const Complex& c) const;

  Complex& operator+=(const Complex& c);
  Complex& operator-=(const Complex& c);
  Complex& operator*=(const Complex& c);
  Complex& operator/=(const Complex& c);

  Complex& operator=(const Complex& c);

  void println() { std::cout << "( " << real << " , " << img << " ) " << std::endl; }
};

Complex Complex::operator+(const Complex& c) const {
  Complex temp(real + c.real, img + c.img);
  return temp;
}
Complex Complex::operator-(const Complex& c) const {
  Complex temp(real - c.real, img - c.img);
  return temp;
}

Complex Complex::operator+(const char* str) const{
    int begin = 0,end = strlen(str);
    double str_img = 0.0, str_real = 0.0;

    int pos_i = -1;
    for(int i = 0; i != end; i++) {
        if(str[i] == 'i') {
            pos_i = i;
            break;
        }
    }

    if (pos_i == -1) {
        str_real = get_number(str, begin, end-1);

        Complex temp(str_real, str_img);
        return (*this) + temp;
    }

    str_real = get_number(str, begin, pos_i -1);
    str_img = get_number(str, pos_i+1, end-1);
    if(pos_i >= 1 && str[pos_i - 1] =='-') str_img *= -1.0;

    Complex temp(str_real, str_img);
    //자주 쓰이는 기법, temp로 임시 객체를 만든 후 리턴한다. 리턴되는순간
    //메모리 삭제가 되기때문에 문제가 없음.
    return (*this) + temp;

}
double Complex::get_number(const char *str, int from, int to) const {
  bool minus = false;
  if (from > to) return 0; // from 이 to보다큰 경우는 예외처리

  if (str[from] == '-') minus = true;
  if (str[from] == '-' || str[from] == '+') from++;

  double num = 0.0;
  double decimal = 1.0;

  bool integer_part = true;
  for (int i = from; i <= to; i++) {
    if (isdigit(str[i]) && integer_part) {
      num *= 10.0;
      num += (str[i] - '0');
/*
str[i] = char형식이므로 '0'을 빼주게 되면 ASCII CODE상 123..789가 일렬로 있기 때문에
실제 정수값을 구할 수 있게 된다!..
*/
    } else if (str[i] == '.')
      integer_part = false;
/*
bool을 이용해 사소한 부분도 나누어준 모습
*/
    else if (isdigit(str[i]) && !integer_part) {
      decimal /= 10.0;
      num += ((str[i] - '0') * decimal);
    } else
      break;  
  }

  if (minus) num *= -1.0;

  return num;
}


/*
사실 다필요없고 그냥 char* str을 인자로받는 생성자를 만들어주면 된다.
*/

Complex::Complex(const char* str) {
  // 입력 받은 문자열을 분석하여 real 부분과 img 부분을 찾아야 한다.
  // 문자열의 꼴은 다음과 같습니다 "[부호](실수부)(부호)i(허수부)"
  // 이 때 맨 앞의 부호는 생략 가능합니다. (생략시 + 라 가정)

  int begin = 0, end = strlen(str);
  img = 0.0;
  real = 0.0;

  // 먼저 가장 기준이 되는 'i' 의 위치를 찾는다.
  int pos_i = -1;
  for (int i = 0; i != end; i++) {
    if (str[i] == 'i') {
      pos_i = i;
      break;
    }
  }

  // 만일 'i' 가 없다면 이 수는 실수 뿐이다.
  if (pos_i == -1) {
    real = get_number(str, begin, end - 1);
    return;
  }

  // 만일 'i' 가 있다면,  실수부와 허수부를 나누어서 처리하면 된다.
  real = get_number(str, begin, pos_i - 1);
  img = get_number(str, pos_i + 1, end - 1);

  if (pos_i >= 1 && str[pos_i - 1] == '-') img *= -1.0;
}

int main(){
    Complex c_str("3+i2");
    Complex c_int(1,2);
    Complex c_copy(c_str);
    c_str.println();
    c_int.println();
    c_copy.println();

    return 0;
}