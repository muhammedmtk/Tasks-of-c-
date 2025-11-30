#include <iostream>
#include <limits>
#include <conio.h>
#include <windows.h>
using namespace std;

void gotoxy(int x, int y) {
    COORD coord = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void textattr(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}


struct employee
{
    char name[20];
    int age;
    int id;
};

// scan data
void employee_scanByAddress(employee* ps)
{
    cout << "Enter the ID of employee: ";
    while (!(cin >> ps->id))
    {
        cout << "Invalid input. Please enter a valid number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Enter the age of employee: ";
    while (!(cin >> ps->age) || ps->age <= 0)
    {
        cout << "Invalid input. Please enter a valid positive age: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cin.ignore();
    cout << "Enter the name of employee: ";
    cin.getline(ps->name, 20);

    cout << "\nEmployee was added successfully.\n";
}
//print data
void display_employee(employee* ps)
{
    cout << "\n------------------------------\n";
    cout << "Employee ID: " << ps->id << endl;
    cout << "Employee Age: " << ps->age << endl;
    cout << "Employee Name: " << ps->name << endl;
    cout << "------------------------------\n";
}

// Stack class
class Stack
{
    int top;
    int size;
    employee* arr;
public:
    Stack(int s)
    {
        size = s;
        top = -1;
        arr = new employee[size];
    }
//is empty
    bool is_empty()
    {
        return top == -1;
         }
         //is full
    bool is_full()
    {
        return top == size - 1;
         }

    void Pushdata()
    {
        if (is_full())
        {
            cout << "The stack is full!\n";
        }
        else
        {
            top++;
            employee_scanByAddress(&arr[top]);
            cout << "New employee was pushed\n";
        }
    }

    void popdata()
    {
        if (is_empty())
        {
            cout << "The stack is empty!\n";
        }
        else
        {
            display_employee(&arr[top]);
            top--;
            cout << "Employee was popped successfully\n";
        }
    }
    //function to print the last employee added
    void printfirstdata()
    {
    display_employee(&arr[top]);
    }

    ~Stack() { delete[] arr; }
};

// Main menu
int main()
{
    int size;
    cout << "Enter the number of employees: ";
    while (!(cin >> size) || size <= 0)
    {
        cout << "Invalid input. Please enter a positive number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    Stack s(size);

    char names[4][30] = { "Add", "Display / Pop", "Display last employee", "Exit" };
int hindex = 0;
char ch;
int flag = 0;

do
{
    system("cls");


    for (int i = 0; i < 4; i++)
    {
        gotoxy(10, 5 + i);
        textattr(hindex == i ? 0x04 : 0x07);
        cout << names[i];
    }

    ch = getch();

    switch (ch)
    {
    case -32:
        ch = getch();
        switch (ch)
        {
        case 72: // up
            hindex = (hindex - 1 + 4) % 4;
            break;
        case 80: // down
            hindex = (hindex + 1) % 4;
            break;
        case 71: // Home
            hindex = 0;
            break;
        }
        break;

    case 13: // Enter
        system("cls");
        if (hindex == 0) // Add
        {
            cout << "You chose: Add / Push\n\n";
            s.Pushdata();
        }
        else if (hindex == 1) // Display / Pop
        {
            cout << "You chose: Display / Pop\n\n";
            s.popdata();
        }
        else if (hindex == 2) // Display last employee
        {
            if (!s.is_empty())
                s.printfirstdata();
            else
                cout << "The stack is empty!\n";
        }
        else // Exit
        {
            cout << "Exiting program...\n";
            flag = 1;
        }

        cout << "\nPress any key to return to the main menu...";
        getch();
        break;
    }

} while (ch != 27 && flag == 0);
return 0; }
