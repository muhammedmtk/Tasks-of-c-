#include <iostream>
#include <cstring>
using namespace std;

  class Bankaccount
    {
private:
    int id;
    char name[20];
    int balance;

    public:
    //constructor
    Bankaccount()
    {
    id=0;
    strcpy(name,"unknown");
    balance=0;
    }
    //setter
    void set_id(int id)
    {
    this->id=id;
    }
    void set_name(char*n)
    {
    strcpy(name,n);
    }
    //deposit
    void deposit_balance(int bal)
    {
    balance+=bal;
    }
    //withdrawing
    void withdraw_balance(int bal)
    {
    balance-=bal;
    }
    //getter
    int get_balance()
    {
    return balance;
    }
    int get_id()
    {
    return id;
    }
    char* get_name()
    {
    return name;
    }
    };

int main()
{
 Bankaccount b;
 b.set_id(10);
 b.set_name("mohamed") ;
 b.deposit_balance(7000);
int balance=b.get_balance();
 cout<<"the balance after deposing:"<<b.get_balance()<<"\n";

 b.withdraw_balance(3000);
 cout<<"the balance after withdrawing:"<<b.get_balance()<<"\n";

 int id=b.get_id();
 cout<<"the id is: "<<id<<"\n";

 char*name=b.get_name();
 cout<<"the name is : "<<name<<"\n";
  return 0;
}
