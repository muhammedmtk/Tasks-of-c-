#include <iostream>

using namespace std;
template <typename T>
T Swap(T &x,T &y)
{
    T temp = x;
    x=y;
    y=temp;
}


int main()
{
    int x=10;
    int y=20;
    cout<<"x="<<x<<"y="<<y<<endl;
    Swap <int>(x,y);
    cout<<"x="<<x<<"y="<<y<<endl;
    return 0;
}
