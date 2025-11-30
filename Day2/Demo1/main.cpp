#include <iostream>
using namespace std;

#define size 10

int main()
{
    int arr[size] = {0};
    int i;
    int num;
    int location = -1;

    // user input the numbers
    for (i = 0; i < size; i++)
    {
        cout << "Enter number " << i + 1 << ": ";
        cin >> arr[i];
    }

    // print the numbers in array
    cout << "\nThe numbers in the array are:\n";
    for (i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // find the min and max of array
    int max = arr[0];
    int min = arr[0];

    for (i = 1; i < size; i++)
    {
        if (max < arr[i])
            max = arr[i];
        if (min > arr[i])
            min = arr[i];
    }

    cout << "\nThe max in array is " << max << endl;
    cout << "The min in array is " << min << endl;

    // search for a number
    cout << "\nEnter the number you want to search: ";
    cin >> num;

    for (i = 0; i < size; i++)
    {
        if (num == arr[i])
        {
            location = i;
            break;
        }
    }

    if (location != -1)
        cout << "Your number " << num << " is in location " << location << " in the array." << endl;
    else
        cout << "Your number isn't in the array." << endl;

    return 0;
}


