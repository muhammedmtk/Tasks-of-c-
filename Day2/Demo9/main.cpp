#include <iostream>
using namespace std;
int main()
{
    int arr[10]= {0};
    int num,x;
    cout<<"enter the first number of array:";
    cin>>num;
    cout<<"enter the second number of array:";
    cin>>x;
    arr[0]=num;
    arr[1]=x;
    for(int i=0; i<10; i++)
    {
        arr[i+2]=arr[i+1]+arr[i];
    }
    for(int i=0; i<10; i++)
    {
        cout<<" "<<arr[i];
    }
    return 0;
}
