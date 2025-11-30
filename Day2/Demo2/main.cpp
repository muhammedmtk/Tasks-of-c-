#include <iostream>

using namespace std;

int main()
{
    int x;
    cout << "Enter your degree: ";
    cin >> x;

    if(x<0||x>100)
    {
        cout<< "invalid degree";
    }
    else if (x < 60)
    {
        cout << "Failed";
    }
    else if (x >= 60 && x < 70)
    {
        cout << "Good";
    }
    else if (x >= 70 && x < 85)
    {
        cout << "Very Good";
    }
    else
    {
        cout << "Excellent";
    }

    return 0;
}
