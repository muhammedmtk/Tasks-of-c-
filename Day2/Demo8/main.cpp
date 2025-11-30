#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
    char ch;
    int flag=0;

    do
        {
        cout<<"\nNew\nDisplay\nExit\n";
        cout << "Enter your choice (N/D/E or ESC to exit): ";
        ch=getch();
        cout << ch << endl;
        switch(ch)
        {
    case'N':
    case'n':
        cout<<"your choose item New";
        break;
    case'd':
    case'D':
        cout<<"you choose item Display";
        break;
    case'E':
    case'e':
        cout<<"you choose item Exit";
        flag=1;
        break;
    case(27):
        cout<<"ESC";
        flag=1;

    default:
        cout<<"enter character E D N";
        break;
        }
        }
    while(flag==0);

    return 0;
}
