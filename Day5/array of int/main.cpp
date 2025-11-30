#include <iostream>

using namespace std;

int main()
{
    int arr[10]={1,2,3,4,5,6,7,8,9,10};
    int*ptr=arr;
    int sizearr=sizeof(arr)/sizeof(arr[0]);
    cout<<endl<<"print the array using array[index]: ";
    for(int i=0;i<10;i++)
        {
        cout<<arr[i]<<" ";
        }
    cout<<endl<<"print the array using *arr+i: ";
    for(int i=0;i<sizearr;i++)
        {
        cout<<*(arr+i)<<" ";
        }
    cout<<endl<<"print the array using ptr[index]: ";
     for(int i=0;i<sizearr;i++)
        {
        cout<<ptr[i]<<" ";
        }
    cout<<endl<<"print the array using *(ptr+i): ";
    for(int i=0;i<sizearr;i++)
        {
        cout<<*(ptr+i)<<" ";
        }
    return 0;
}
