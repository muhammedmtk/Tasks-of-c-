#include <iostream>
#define size 10
using namespace std;

int main()
{
    int largest_space=0;
    int arr[size]= {0};
    int flag=0;
    int max=0;
    //input the numbers of array
    for(int i=0; i<size; i++)
    {
        cout<<"enter the "<<i+1<<" number:";
        cin>>arr[i];
    }
    //print the numbers of array
    cout<<endl<<"the numbers of array: ";
    for(int i=0; i<size; i++)
    {
        cout<<arr[i]<<" ";
    }
    //find the largest space between the same numbers
    for(int i=0; i<size; i++)
    {
        int k;
        for(k=0; k<i; k++)
        {
            if(arr[k]==arr[i])
                flag=1;
        }
        if(flag==1)
        {
            continue;
        }
        else
        {
            for(int j=size-1; j>i; j--)
            {
                if(arr[i]==arr[j])
                {
                    largest_space=j-i;
                    break;
                }
            }
            if(largest_space>max)
            {
                max=largest_space;
            }
        }

    }
    cout<<"the largest space is "<<max;
    return 0;
}
