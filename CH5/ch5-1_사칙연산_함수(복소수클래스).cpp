#include <iostream>

class Complex {
    private :
        double real, img;

    public :
        Complex(double real, double img) : real(real),img(img) {}
        //생성자 초기화 리스트
        Complex(const Complex& c) { real = c.real, img = c.img;}

        //Complex() 와 Complex func()를 잘 구분해야함 ㅋㅋ.. 전자는 생성자이
        //고 후자는 Complex를 반환하는 함수
        Complex operator+(const Complex& c) const;
        Complex operator-(const Complex& c) const;
        Complex operator*(const Complex& c) const;
        Complex operator/(const Complex& c) const;

        void println() { std::cout << "( " << real << " , "<<img<<" )"<<std::endl; }
};



/*Complex를 인자로 받는 함수에서의 주의점
Complex::operator+를 한순간, Complex class 안에서 작업하는 것과 동일하기 때문에,
Complex의 private 변수에 제한없이 접근할 수 있다. 이때, Complex 인 c를 참조해왔기 때문에,
c의 private변수는 .을 통해 접근한다.

더불어 Complex& c의 값만 가져오고 수정을 하는 것이 아니라면 항상 const를 붙여주는 것이 바람직하다.
또한 operator+함수역시 Complex의 값을 수정하는 것이 아니기 때문에 const function으로 지정해주는것이
바람직하다.

*/
Complex Complex::operator+(const Complex& c) const {
    Complex temp(real + c.real, img + c.img);
    return temp;
}
Complex Complex::operator-(const Complex& c) const {
  Complex temp(real - c.real, img - c.img);
  return temp;
}
Complex Complex::operator*(const Complex& c) const {
  Complex temp(real * c.real - img * c.img, real * c.img + img * c.real);
  return temp;
}
Complex Complex::operator/(const Complex& c) const {
  Complex temp(
    (real * c.real + img * c.img) / (c.real * c.real + c.img * c.img),
    (img * c.real - real * c.img) / (c.real * c.real + c.img * c.img));
  return temp;
}
//d
int main() {
  Complex a(1.0, 2.0);
  Complex b(3.0, -2.0);

  Complex c = a * b;

  c.println();
}
