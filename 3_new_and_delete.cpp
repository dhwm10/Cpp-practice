#include <iostream>

int main(){
    int arr_size;
    std::cout << "array size : ";
    std::cin >> arr_size;
    int *list = new int[arr_size];
    for (int i=0; i<arr_size; i++){ //for문 속 i는 for문의 내부변수 이므로 for문이 종료되는 시점에서 소멸한다
        std::cin >> list[i];
    }
    for (int i=0; i<arr_size; i++){ //따라서 여기서 다시 i를정의한다고해서 위의 for문의 i가 영향을 주지않는다.
        std::cout << i << "th element of list : "<<list[i]<<std::endl;
    }
    delete[] list; //new로 할당한 것을 해제해준다.
    return 0;

}