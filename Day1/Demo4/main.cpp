#include <iostream>

using namespace std;

int main()
{
    char x,y;
    cout<<"enter the character:";
    cin>>x;
    if(x>=65&&x<=90)
        {
        //y=x+32;
        y='a'+(x-'A');
        }
    else if(x>=97&&x<=122)
        {
        //y=x-32;
        y='A'+(x-'a');
        }
    cout<<y;
    return 0;
}
