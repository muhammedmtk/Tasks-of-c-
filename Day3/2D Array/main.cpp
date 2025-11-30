#include <iostream>
#define col 4
#define row 3
using namespace std;

int main()
{
    //input the numbers of 2d array
    int arr[row][col]= {0};
    int i,j;
    for(i=0; i<row; i++)
    {
        cout<<"enter the numbers of row "<<i+1<<endl;
        for(j=0; j<col; j++)
        {
            cout<<"enter the num "<<j+1<<":";
            cin>>arr[i][j];
        }
    }

    //output the numbers of 2d array
    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            cout<<arr[i][j]<<"\t";
        }
        cout<<endl;
    }

    //sum of rows of 2d array
    int sum[3]= {0};
    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            sum[i]+=arr[i][j];
        }
    }

    for(i=0; i<row; i++)
    {
        cout<<"the sum of "<<i+1<<" row:"<<sum[i]<<endl;
    }

    //the avg of each col
    int avg[4]= {0};
    for(i=0; i<col; i++)
    {
        for(j=0; j<row; j++)
        {
            avg[i]+=arr[j][i];
        }
    }

    for(i=0; i<4; i++)
    {
        cout<<"the avg of col "<<i+1<<" is "<<avg[i]/row<<endl;
    }
return 0;
}




