#include <iostream>

using namespace std;

int main()
{
    int x,y;
    cout<<"enter first number:";
    cin>>x;
    cout<<"enter second number:";
    cin>>y;
    cout<<"x+y="<<x+y<<endl;
    cout<<"x-y="<<x-y<<endl;
    cout<<"x*y="<<x*y<<endl;
    if (y==0)
        {
        cout<<"you can't divide by 0";
        }
    else
        {
        cout<<"x/y="<<x/y<<endl;
        }
    return 0;
}
