#include <iostream>
#include <cstring>
using namespace std;
class Emp
{
private:
    int id;
    char name[10];
    int age;
    int salary;
public:
    //constructor
    Emp()
    {
        id=0;
        strcpy(name,"unknown");
        age=0;
        salary=7000;
    }
    //setter
    void set_name(char*n)
    {
        strcpy(name,n);
    }
    void set_age(int age)
    {
        this->age= age;
    }
    void set_id(int id)
    {
        this->id=id;
    }
    void set_salary(int sal)
    {
        if(sal<7000)
        {
            salary=7000;
        }
        else
        {
            this->salary=sal;
        }
    }
    //getter
    int get_age()
    {
        return age;
    }
    int get_id()
    {
        return id;
    }
    int get_salary()
    {
        return salary;
    }
    char* get_name()
    {
    return name;
    }


};
int main()
{
    Emp e;
    e.set_name("mohamed");
    e.set_age(26);
    e.set_salary(8000);
    e.set_id(33);


    int age=e.get_age();
    int id=e.get_id();
    char*name=e.get_name();
    int salary=e.get_salary();

    cout<<"the name is: "<<name<<"\n";
    cout<<"the salary is: "<<salary<<"\n";
    cout<<"the age is: "<<age<<"\n";
    cout<<"the id is: "<<id<<"\n";
    return 0;
}
