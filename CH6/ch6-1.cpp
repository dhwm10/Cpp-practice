#include <string>
#include <iostream>

class Employee {
    std::string name;
    int age;

    std::string position;
    int rank;
    public:
        Employee(std::string name, int age, std::string position, int rank):
         name(name), age(age), position(position), rank(rank) {}
        
        Employee(const Employee& employee) {
            name = employee.name;
            age = employee.age;
            position = employee.position;
            rank = employee.rank;
        }

        Employee() {}

        void print_info() {
            std::cout << name << " (" << position <<  " , " <<age <<") ==> "
            <<calculation_pay() << "won" << std::endl;
        }
        int calculation_pay() { return 200 + rank * 50;}

};


/*
포인터를 저장하는 배열자체가 이중포인터와 동일하다
int ** x = new int *[10];
*/

class EmployeeList {
    int alloc_employee;
    int current_employee;
    Employee** employee_list;

    public:
        EmployeeList(int alloc_employee) : alloc_employee(alloc_employee) {
            employee_list = new Employee *[alloc_employee];
            current_employee = 0;
        }
        //Employee* 객체포인터?인 employee 
        void add_employee(Employee* employee) {
            employee_list[current_employee] = employee;
            /*
            employee_list : 이중포인터이므로 employee_list[~]가 가리키는 것이 포인터여야함.
            employee_list + i => pointer를 가리키는 pointer // employee[i] => pointer(Employee객체를 가리키는)
            */
            current_employee ++;
        }
        int current_employee_num() { return current_employee; }

        void print_employee_info() {
            int total_pay = 0;
            for (int i=0; i<current_employee; i++) {
                employee_list[i]->print_info();
                /*
                포인터 객체와 더불어 이중포인터 배열을 쓰는 이유는 아마 이거일 것같음.
                포인터 객체로 배열에 저장할 경우 이렇게 ->를 사용하여 멤버 함수에 접근하기가
                굉장히 용이해짐 그리고 생각해보니까 포인터로 저장하는것 외에 방법이 없음 ㅋㅋㅋ
                */
                total_pay += employee_list[i] ->calculation_pay(); //Employee클래스의 calculation_pay()에 접근

               
                
            }
            std::cout << "total pay : "<<total_pay<<"won"<<std::endl;
        }
        ~EmployeeList() {
            for (int i=0; i< current_employee; i++){
                delete employee_list[i];
            }
            delete[] employee_list;
        }
};


int main(){
    return 0;
}


