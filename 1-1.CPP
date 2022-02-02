#include <iostream>
#include "header1.h" // header1.h를 include
#include "header2.h" // header2.h를 include

using namespace header1_name; // namespace를 header1_name만 사용하겠다.

namespace header1_name {
    int func(){
        var(); // header1_name공간이기 때문에 var()을 바로 사용해도 header1_name::var()로 인식
    }
}

int main(){
    var(); // header1_name의 namespace를 사용하고있으므로, 자동으로 header1_name::var()
    func(); // header1_name에서 저의한 func함수
    header2_name::var(); //header1_name 공간을 이용중이므로 header2_name에 접근할 것이라고 명시
    return 0;
}