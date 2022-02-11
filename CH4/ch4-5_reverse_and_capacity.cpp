#include <iostream>
#include <string.h>

class MyString {
  char* string_content; 
  int string_length;    
  int memory_capacity;   

 public:
 
  MyString(char c);

  MyString(const char* str);

  MyString(const MyString& str);

  ~MyString();

  int length() const;
  //----------------reserve and capacity function---------------//
  int capacity() const;
  void reserve(int size);

  void print() const;
  void println() const;

  MyString& assign(const MyString& str);
  MyString& assign(const char* str);
};

int MyString::capacity() const { return memory_capacity; }
void MyString::reserve(int size) {
    if (size > memory_capacity) {
        char* prev_string_content = string_content;


    }
}

MyString& MyString::assign(const MyString& str) {
    if (str.string_length > memory_capacity) { //memory_capacity를 도입함으로써, 기존에 메모리가 얼마나 할당 되있는지 미리 확인하고 들어간다.
        delete[] string_content;
/*
memory_capacity를 도입했기 때문에, 긴 메모리가 할당되있지만 모두 쓰지 않는경우, 새롭게 메모리를
할당하는 낭비적인 과정을 생략하는 것이 가능해졌다. 즉, string_length로판단하는 것이 아닌,
memory_capacity로 판단하자는 것이다.
*/
        string_content = new char[str.string_length];
//먼저 동적할당을 통해 string_content의 메모리를 늘려준다.
        memory_capacity = str.string_length;
//memory_capacity를 다시 늘려주는 모습. (기록)
    }
    for (int i = 0; i != str.string_length; i++) {
        string_content[i] = str.string_content[i]; //(저장)
    }

    string_length = str.string_length;
    return *this;
}

MyString& MyString::assign(const char* str) {
    int str_length = strlen(str);
    if (str_length > memory_capacity) {
        delete[] string_content;

        string_content = new char[str_length];
        memory_capacity = str_length;
    }
    for (int i = 0; i != str_length; i++) {
        string_content[i] = str[i];
    }

    string_length = str_length;

    return *this;
}

int MyString::capacity() const{ return memory_capacity;}

/*
reserve의 역할 : 미리 size 값을 받아서 memory_capacity와 비교하여, 기존의 string_content의
memory_capacity를 늘려놓는다. (주소는 다르고, 크기는 늘어남)이때 string_content의 내용(주소)을 그대로 복사해야하기 때문에,
prev_string_content를 만들어 복사해놓고 다시 string_content를 size크기만큼 동적할당하여,
prev_string_content에 저장해놨던 값을 다시 집어넣는다.
이렇게함으로써 값은 그대로이지만, memory_capacity는 늘어난 효과를 볼 수 있다.
*/



void MyString::reserve(int size) {
    if (size > memory_capacity) {
        char *prev_string_content = string_content; 
//prev_string_content에 string content의 주소를 저장해놓는다.

        string_content = new char[size];
//string_content를 재할당하여 다른 주소로 옮긴다. 이때, 새로운 주소로 옮겼으므로 string_content의 내용은 없어지며
        memory_capacity = size;

        for ( int i = 0; i != string_length; i++)
            string_content[i] = prev_string_content[i];
//여기서 prev_string_content의 주소(기존의 string_content주소)에 저장된 값을 옮겨심는다/
        delete[] prev_string_content;
//prev_string_content 는 기존의 string_content의 정보를 갖고있기 때문에, delete를 통해 최적화를 시켜준다.
    }
}