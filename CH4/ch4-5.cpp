#include <iostream>
#include <string.h>

class MyString {
    char* string_content;  //정보 1. 문자열정보 (기존의 c에선 char* 형식을 사용해 문자열 표현)
    int string_length;     //정보 2. 문자열 길이

    public :
        MyString(char c);              //1개의 문자
        MyString(const char* str);     //char* 형식의 문자열
        MyString(const MyString& str); //복사 생성자

};

MyString::MyString(char c) {
    string_length = 1;
    string_content = new char[1]; // string_content에 char[1]크기만큼 동적할당
    string_content[0] = c;        //string content[0] 에 c 전달
}
MyString::MyString(const char* str) {
    string_length = strlen(str);
    string_content = new char[string_length];

    for (int i = 0; i != string_length; i++) string_content[i] = str[i];
}