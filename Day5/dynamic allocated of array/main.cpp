#include <iostream>

using namespace std;

int main()
{
    int size;
    cout<<"enter the size of array:";
    cin>>size;
    int*ptr=new int[size];
    cout<<"print the numbers into array"<<endl;
    for(int i=0;i<size;i++)
        {
        cout<<"enter the number "<<i+1<<" : ";
        cin>>ptr[i];
        }
    cout<<"the numbers of your array:\n";
    for(int i=0;i<size;i++)
        {
        cout<<ptr[i]<<" ";
        }
    delete ptr;
    return 0;
}
