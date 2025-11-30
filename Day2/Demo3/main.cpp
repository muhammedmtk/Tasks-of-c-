#include <iostream>

using namespace std;

int main()
{
    int total,nums,sum=0;
    cout<<"enter the total of numbers:";
    cin>>total;
    for(int i=0;i<total;i++)
        {
        cout<<"enter the "<<i+1<<" number:";
        cin>>nums;
        sum+=nums;
        }
    cout<<"sum="<<sum;
    return 0;
}
